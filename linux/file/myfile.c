#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
  int fd = open("log.txt", O_WRONLY|O_TRUNC);
  if(fd < 0)
  {
    perror("open");
    return 1;
  }
  const char* msg = "aaa";
  write(fd, msg, strlen(msg));


  close(fd);

  return 0;
}

// int main() {
//   chdir("/home/max/code/test/");
//   FILE *pf = fopen("log.txt", "w");
//   if (pf == NULL) {
//     perror("fopen");
//     return 1;
//   }
//   printf("pid: %d\n", getpid());

//   fclose(pf);
//   sleep(1000);
//   return 0;
// }
