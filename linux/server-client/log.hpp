#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <cstdarg>
#include <cstdio>

// print log

#define INFO 1
#define WARNING 2
#define ERROR 3
#define FATAL 4
#define DEBUG 5

#define SIZE 1024

#define FILENAME "/log.txt"

enum print
{
    SCREEN,
    LOG_TEXT,
    CLASSIC_TEXT
};

class Log
{
public:
    Log(int printState = SCREEN, const std::string &path = "./log/")
        : _printState(printState), _path(path)
    {
    }
    std::string getString(int level)
    {
        switch (level)
        {
        case INFO:
            return "INFO";
        case WARNING:
            return "WARNING";
        case ERROR:
            return "ERROR";
        case FATAL:
            return "FATAL";
        case DEBUG:
            return "DEBUG";
        default:
            return "NONE";
        }
    }

    void log_message(int level, const char *format, ...)
    {
        // time
        time_t t = time(nullptr);
        struct tm *local = localtime(&t);

        char leftBuffer[SIZE] = {0};
        snprintf(leftBuffer, sizeof(leftBuffer), "[%s][%d-%d-%d %d:%d:%d]", getString(level).c_str(), local->tm_year + 1900,
                 local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);

        va_list s;
        va_start(s, format);
        char rightBuffer[SIZE] = {0};
        vsnprintf(rightBuffer, sizeof(rightBuffer), format, s);

        char logTxt[SIZE * 2] = {0};
        snprintf(logTxt, sizeof(logTxt), "%s %s", leftBuffer, rightBuffer);

        printf("%s\n", logTxt);
    }

    void operator()(int level, const char *format, ...)
    {
        // time
        time_t t = time(nullptr);
        struct tm *local = localtime(&t);

        char leftBuffer[SIZE] = {0};
        snprintf(leftBuffer, sizeof(leftBuffer), "[%s][%d-%d-%d %d:%d:%d]", getString(level).c_str(), local->tm_year + 1900,
                 local->tm_mon + 1, local->tm_mday, local->tm_hour, local->tm_min, local->tm_sec);

        va_list s;
        va_start(s, format);
        char rightBuffer[SIZE] = {0};
        vsnprintf(rightBuffer, sizeof(rightBuffer), format, s);
        va_end(s);

        char logTxt[SIZE * 2] = {0};
        snprintf(logTxt, sizeof(logTxt), "%s %s", leftBuffer, rightBuffer);

        // printf("%s\n", logTxt);

        switch (_printState)
        {
        case SCREEN:
            std::cout << logTxt << std::endl;
            break;
        case LOG_TEXT:
            log_in_text(logTxt);
            break;
        case CLASSIC_TEXT:
            log_diff_text(level, logTxt);
            break;
        default:
            break;
        }
    }

    void log_in_text(const std::string &logTxt)
    {
        std::string fileName = _path + FILENAME;
        int fd = open(fileName.c_str(), O_WRONLY|O_CREAT|O_APPEND, 0664);
        if(fd < 0)
        {
            return;
        }
        write(fd, logTxt.c_str(), logTxt.size());
        close(fd);
    }

    void log_diff_text(int level, const std::string &logTxt)
    {
        std::string filename = _path;
        filename += FILENAME;
        filename += ".";
        filename += getString(level);
        int fd = open(filename.c_str(), O_WRONLY|O_CREAT|O_APPEND, 0664);
        if(fd < 0)
        {
            return;
        }
        write(fd, logTxt.c_str(), logTxt.size());
        close(fd);
    }

    ~Log() {}
private:
    int _printState;
    std::string _path;
};
