#ifndef MY_STDIO_H
#define MY_STDIO_H 

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 1024

typedef struct IO_FILE 
{
  int fileno;
  int flag;
  char out_buffer[SIZE];
  int out_pos;
} _FILE;

_FILE *_fopen(const char *filename, const char *mode);
size_t _fwrite(const char *msg, size_t size, size_t nmeb, _FILE *f);
void _fclose(_FILE *f);

#endif 
