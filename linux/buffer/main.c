#include "my_stdio.h"

int main()
{
  const char *msg = "hello world\n";
  _FILE *f = _fopen("log.txt", "a");
  int cnt = 5;
  while (cnt > 0)
  {
    _fwrite(msg, strlen(msg), 1, f);
    cnt--;
    sleep(1);
  }


  _fclose(f);
  return 0;
}
