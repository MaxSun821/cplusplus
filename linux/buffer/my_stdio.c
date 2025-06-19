#include "my_stdio.h"

#define FILE_PERMISSIONS 0666
#define FLUSH_NOW 1
#define FLUSH_LINE 2
#define FLUSH_ALL 4


_FILE *_fopen(const char *filename, const char *mode)
{
  assert(filename);
  assert(mode);
  int fd = 0;
  int flag = 0;

  if (strcmp(mode, "w") == 0)
  {
    // 创建新文件,清空文件内容
    flag = (O_CREAT|O_WRONLY|O_TRUNC);
    fd = open(filename, flag, FILE_PERMISSIONS);
  }
  else if (strcmp(mode, "a") == 0)
  {
    flag = (O_CREAT|O_WRONLY|O_APPEND);
    fd = open(filename, flag, FILE_PERMISSIONS);
  }
  else if (strcmp(mode, "r") == 0)
  {
    flag = O_RDONLY;
    fd = open(filename, flag, FILE_PERMISSIONS);
  }
  else 
  {
    return NULL;
  }
  if (fd == -1) return NULL;
  _FILE *f = (_FILE*)malloc(sizeof(_FILE));
  if (f == NULL) return NULL;
  f->fileno = fd;
  f->flag = FLUSH_LINE;
  f->out_pos = 0;
  return f;
}

size_t _fwrite(const char *msg, size_t size, size_t nmeb, _FILE *f)
{
  memcpy(&f->out_buffer[f->out_pos], msg, size * nmeb);
  f->out_pos += size * nmeb;
  int n = 0;
  if (f->flag & FLUSH_NOW)
  {
    n = write(f->fileno, f->out_buffer, f->out_pos);
    f->out_pos = 0;
  }
  else if (f->flag & FLUSH_LINE)
  {
    if (f->out_buffer[f->out_pos - 1] == '\n')
    {
      n = write(f->fileno, f->out_buffer, f->out_pos);
      f->out_pos = 0;
    }
    else 
    {
      return size * nmeb;
    }
  }
  else if (f->flag & FLUSH_ALL)
  {
    if (f->out_pos == SIZE)
    {
      n = write(f->fileno, f->out_buffer, f->out_pos);
      f->out_pos = 0;
    }
    else 
    {
      return size * nmeb;
    }
  }
  return n;
}

void _fflush(_FILE *f)
{
  write(f->fileno, f->out_buffer, f->out_pos);
}

void _fclose(_FILE *f)
{
  _fflush(f);
  close(f->fileno);
  free(f);
}
