#!/bin/sh

cd include

for D in tinyxml sqlite_modern_cpp
do
  find ../src/${D}/ -name '*.h' -exec ln -s {} \;
done
ln -s ../src/sqlite_modern_cpp/hdr/sqlite_modern_cpp/

cd -
