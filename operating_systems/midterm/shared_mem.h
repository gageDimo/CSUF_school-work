#ifndef shared_mem_h
#define shared_mem_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/unistd.h>
#include <sys/mman.h>

extern const int SIZE;
extern const char* NAME;

void shared_write(char* pmem, const char* msg, size_t* sizeleft);
void shared_read(char* pmem);

#endif /* shared_mem_h */
