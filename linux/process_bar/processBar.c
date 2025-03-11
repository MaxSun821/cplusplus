#include "processBar.h"
#include <stdio.h>

char bar[102];

void processBar(int rate) {
  if (rate < 0 || rate > 100) {
    return;
  }
  static const char *roll = "|/-\\";
  int len = strlen(roll);

  printf("[%-100s][%d%%][%c]\r", bar, rate, roll[rate % len]);
  fflush(stdout);
  bar[rate++] = BODY;
  if (rate < LOAD)
    bar[rate] = TOP;
}

void initBar() { memset(bar, '\0', sizeof(bar)); }
