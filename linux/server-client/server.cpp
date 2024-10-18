#include "command.hpp"
#include "log.hpp"

int main()
{
    
    Info info;
    Log log(CLASSIC_TEXT);

    // open pipe
    // server need to read
    int fd = open(FIFO_NAME, O_RDONLY);

    // read from client
    if(fd > 0)
    {
        while(true)
        {
            char buffer[1024] = {0};
            int x = read(fd, buffer, sizeof(buffer));
            if(x)
            {
                buffer[x] = 0;
                std::cout << "client send a message to you: " << buffer << std::endl;
            }
            else if(x == 0)
            {
                log(INFO, "server quit, error string: %s, error code: %d", strerror(errno), errno);
                break;
            }
            else
            {
                break;
            }
            
        }
    }
    else if(fd == -1)
    {
        log(WARNING, "server read fail, error string: %s, error code: %d", strerror(errno), errno);
        return errno;
    }

    // close file
    close(fd);


    return 0;
}