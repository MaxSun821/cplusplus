#include "processBar.h"
#include <unistd.h>

typedef void (*callback_t)(int); // 函数指针

void download(callback_t cb) {
  initBar();
  int total = 1000; // 软件总体积
  int cur = 0;

  while (cur <= total) {
    usleep(50000);
    int rate = cur * 100 / total;
    cb(rate);
    cur += 10;
  }
  printf("\n");
}

int main() {
  download(processBar);
  return 0;
}
