################################################################################
## Makefile for GNU Make, find (GNU findutils) 4.4.2 and gcc
# requare GNU Make version 4.0
TARGET_EXEC ?= intermon

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
INC_FLAGS += -I/opt/local/include

LDFLAGS ?= -lpthread -ldl
CPPFLAGS ?= $(INC_FLAGS) -MMD -MP
CXXFLAGS ?= $(INC_FLAGS) -std=c++11 -pthread

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)
	echo;echo run intermon from directory build at current place

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


sonar: sonar_cppcheck sonar_runtests sonar_coverage sonar_sonar

CPPCHECK_INCLUDES = -Isrc/include
SOURCES_TO_ANALYSE = src

# Run cppcheck, a general purpose static code checker
sonar_cppcheck:
	cppcheck -v --enable=all -i src/tinyxml -i src/sqlite_modern_cpp --xml $(CPPCHECK_INCLUDES) $(SOURCES_TO_ANALYSE) 2> $(BUILD_DIR)/cppcheck-report.xml

# Run vera: static code checker focusing on code style issues
sonar_vera:
	bash -c 'find src -regex ".*\.cc\|.*\.hh" | vera++ - -showrules -nodup |& vera++Report2checkstyleReport.perl > $(BUILD_DIR)/vera++-report.xml'

# Run some tests. This run provides:
# 1) test execution report
# 2) valgrind/memcheck report
# 3) raw coverage data (.gcda-files)
sonar_runtests:
	-valgrind --xml=yes --xml-file=$(BUILD_DIR)/valgrind-report.xml $(BUILD_DIR)/intermon --gtest_output=xml:$(BUILD_DIR)/xunit-report.xml

# Collect the coverage data and convert it to cobertura-format
sonar_coverage:
	gcovr -x -r . > $(BUILD_DIR)/gcovr-report.xml

# Parse collected data and feed it into sonar
sonar_sonar:
	sonar-scanner -X

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p

#EOF
