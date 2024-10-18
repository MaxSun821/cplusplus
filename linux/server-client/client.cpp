#include "command.hpp"
#include "log.hpp"

int main()
{
    Log log(CLASSIC_TEXT);
    // open pipe
    // client need to write
    int fd = open(FIFO_NAME, O_WRONLY);

    if(fd < 0)
    {
        log(WARNING, "client write fail, error string: %s, error code: %d", strerror(errno), errno);
        return errno;
    }

    // write
    std::string line;

    while(true)
    {
        std::cout << "What do you want to send? >";
        getline(std::cin, line);

        write(fd, line.c_str(), line.size());
    }

    // close file
    close(fd);

    return 0;
}