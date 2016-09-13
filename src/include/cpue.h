#pragma once
#ifndef _CPUE_H_
#define _CPUE_H_

#ifdef __APPLE__
# define MY_NOSIGNAL SO_NOSIGPIPE
#else
# define MY_NOSIGNAL MSG_NOSIGNAL
#endif

int fd_pipepair(int fd[2]);
int myusleep(long usec);
int set_nonblock(int fd);

#endif  /* _CPUE_H_ */
