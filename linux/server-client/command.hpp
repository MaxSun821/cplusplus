#pragma once
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <string>
#include "log.hpp"

#define FIFO_NAME "./myfifo"
#define MODE 0664

// class create pipe
class Info
{
public:
    Info()
    {
        // create pipe
        int n = mkfifo(FIFO_NAME, MODE);
        if(n == -1)
        {
            // error
            perror("mkfifo");
            exit(1);
        }
    }
    ~Info()
    {
        // unlink pipe
        int n = unlink(FIFO_NAME);
        if(n == -1)
        {
            // error
            perror("unlink");
            exit(1);
        }
    }
};