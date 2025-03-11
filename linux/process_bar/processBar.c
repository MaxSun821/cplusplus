#include "processBar.h"

void processBar() {
  char bar[102];
  static const char *roll = "|/-\\";
  memset(bar, '\0', sizeof(bar)); // 初始化
  int count = 0;
  int len = strlen(roll);

  while (count <= LOAD) {
    printf("[%-100s][%d%%][%c]\r", bar, count, roll[count % len]);
    bar[count++] = BODY;
    if (count < LOAD)
      bar[count] = TOP;
    fflush(stdout);
    usleep(50000);
  }
  printf("\n");
}
