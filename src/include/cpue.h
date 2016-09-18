#pragma once
#ifndef _CPUE_H_
#define _CPUE_H_

#ifdef __APPLE__
# define MY_NOSIGNAL SO_NOSIGPIPE
#else
# define MY_NOSIGNAL MSG_NOSIGNAL
#endif

#define MYUSLEEP_1SEC 1000000
#define MYUSLEEP_3SEC 3000000

int fd_pipepair(int fd[2]);
int myusleep(long usec);
int set_nonblock(int fd);

#endif  /* _CPUE_H_ */
