#include "my_stdio.h"


#define MODE 0666

_FILE* _fopen(const char* filename, const char* flag)
{
    int f = 0;
    int fd = -1;

    if(strcmp(flag, "w") == 0)
    {
        // 以写方式打开
        f = O_CREAT|O_WRONLY|O_TRUNC;
        fd = open(filename, f, MODE);
    }
    else if(strcmp(flag, "a") == 0)
    {
        // 以追加方式打开
        f = O_CREAT|O_WRONLY|O_APPEND;
        fd = open(filename, f, MODE);
    }
    else if(strcmp(flag, "r") == 0)
    {
        // 以读方式打开
        f = O_RDONLY;
        fd = open(filename, f);
    }
    else
    {
        return NULL;
    }

    if(fd == -1)
    {
        // 打开失败
        return NULL;
    }

    _FILE* fp = (_FILE*)malloc(sizeof(_FILE));
    if(fp == NULL)
    {
        return NULL;
    }
    fp->fileno = fd;
    // fp->flag = FLUSH_LINE;
    fp->flag = FLUSH_ALL;
    fp->out_pos = 0;

    return fp;

}
int _fwrite(_FILE* fp, const char* s, int len)
{
    memcpy(&fp->outbuffer[fp->out_pos], s, len);
    fp->out_pos += len;

    if(fp->flag & FLUSH_NOW)
    {
        // 无缓冲
        write(fp->fileno, fp->outbuffer, fp->out_pos);
        fp->out_pos = 0;
    }
    else if(fp->flag & FLUSH_LINE)
    {
        if(fp->outbuffer[fp->out_pos - 1] == '\n')
        {
            // 行缓冲
            write(fp->fileno, fp->outbuffer, fp->out_pos);
            fp->out_pos = 0;
        }
    }
    else if(fp->flag & FLUSH_ALL)
    {
        if(fp->out_pos >= SIZE)
        {
            write(fp->fileno, fp->outbuffer, fp->out_pos);
            fp->out_pos = 0;
        }
    }
    return len;
}

void _fflush(_FILE* fp)
{
    write(fp->fileno, fp->outbuffer, fp->out_pos);
    fp->out_pos = 0;
}

void _fclose(_FILE* fp)
{
    if(fp == NULL)
    {
        return;
    }
    _fflush(fp);
    close(fp->fileno);
    free(fp);
}