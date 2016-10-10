// #include <apue.h>
#include <cpue.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
#include <sys/select.h>

int fd_pipepair(int fd[2]) {
    return socketpair(AF_UNIX, SOCK_STREAM, 0, fd);
}

int myusleep(long usec) {
    struct timeval tv;
    tv.tv_sec  = usec/1000000L;
    tv.tv_usec = usec%1000000L;
    return select(0, 0, 0, 0, &tv);
}

int set_nonblock(int fd) {
    int flags;
#if defined(O_NONBLOCK)
    if (-1 == (flags = fcntl(fd, F_GETFL, 0))) flags = 0;
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
#else
    flags = 1;
    return ioctl(fd, FIOBIO, &flags);
#endif
}

static struct tm tmEpoch = {0};
time_t epoch() { return mktime(&tmEpoch); }

