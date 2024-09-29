#include "my_stdio.h"

int main()
{
    char* msg = "hello my_stdio\n";
    _FILE* fp = _fopen("log.txt", "a");
    int count = 5;
    while(count > 0)
    {
        _fwrite(fp, msg, strlen(msg));
        count--;
        sleep(1);
    }
    _fclose(fp);
    return 0;
}