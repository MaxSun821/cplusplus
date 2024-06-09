#include "processBar.h"

void process_bar()
{
  char bar[NUM];
  int count = 0;
  memset(bar, '\0', sizeof(bar)); //初始化数组

  const char* label = "|/-\\";
  size_t len = strlen(label);
  while(count <= 100)
  {
    printf("[%-100s][%-3d%%][%c]\r", bar, count, label[count % len]);
    fflush(stdout);
    bar[count++] = STYLE;
    if(count < 100)
    {
      bar[count] = '>';
    }
    usleep(50000);
  }
  printf("\n");
}
