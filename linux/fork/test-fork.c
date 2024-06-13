#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t id = fork();

  if (id == 0) {
    // 子进程
    while (1) {
      printf("这是一个子进程，pid: %d, ppid: %d\n", getpid(), getppid());
      sleep(1);
    }
  } else {
    while (1) {
      printf("这是一个父进程，pid: %d, ppid: %d\n", getpid(), getppid());
      sleep(1);
    }
  }

  return 0;
}
