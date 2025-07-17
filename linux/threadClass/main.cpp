#include "Thread.hpp"
#include <iostream>
#include <unistd.h>

void print()
{
    while (true)
    {
        std::cout << "hello world" << std::endl;
        sleep(1);
    }
    
}

int main()
{
    Thread t(print);
    t.run();

    t.join();
    return 0;
}