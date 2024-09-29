#ifndef __MYSTDIO_H__
#define __MYSTDIO_H__

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 1024
#define FLUSH_NOW 1
#define FLUSH_LINE 2
#define FLUSH_ALL 4


typedef struct _IO_FILE
{
    int fileno;
    int flag;
    char outbuffer[1024];
    int out_pos;
}_FILE;


_FILE* _fopen(const char* filename, const char* flag);
int _fwrite(_FILE* fd, const char* s, int len);
void _fclose(_FILE* fp);


#endif