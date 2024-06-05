#include "processBar.h"

void process_bar()
{
  char bar[NUM];
  int count = 0;
  memset(bar, '\0', sizeof(bar)); //初始化数组

  while(count <= 100)
  {
    printf("[%-100s][%-3d%%]\r", bar, count);
    fflush(stdout);
    bar[count++] = '=';
    usleep(50000);
  }
  printf("\n");
}
