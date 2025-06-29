#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class Logger
{
public:
    enum LogLevel
    {
        INFO,
        WARNING,
        ERROR,
        FATAL,
        DEBUG
    };

    // 构造函数，设置日志文件名
    Logger(const std::string &filename)
    {
        log_file_.open(filename, std::ios::out | std::ios::app);
        if (!log_file_)
        {
            std::cerr << "无法打开日志文件" << std::endl;
        }
    }

    // 析构函数，关闭文件
    ~Logger()
    {
        if (log_file_.is_open())
        {
            log_file_.close();
        }
    }

    // 设置日志级别
    void setLogLevel(LogLevel level)
    {
        log_level_ = level;
    }

    // 输出日志
    void log(LogLevel level, const std::string &message)
    {
        if (level >= log_level_)
        {
            std::string level_str = logLevelToString(level);
            std::string timestamp = getCurrentTime();

            log_file_ << "[" << timestamp << "] [" << level_str << "] " << message << std::endl;
            std::cout << "[" << timestamp << "] [" << level_str << "] " << message << std::endl;
        }
    }
private:
    // 获取当前时间
    std::string getCurrentTime()
    {
        time_t now = time(nullptr);
        struct tm *local_time = localtime(&now);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);
        return std::string(buffer);
    }

    // 将枚举转换成字符串
    std::string logLevelToString(LogLevel level)
    {
        switch (level)
        {
            case INFO:    return "INFO";
            case WARNING: return "WARNING";
            case ERROR:   return "ERROR";
            case FATAL:   return "FATAL";
            case DEBUG:   return "DEBUG";
            default:      return "UNKNOWN";
        }
    }

    std::ofstream log_file_; // 日志文件流
    LogLevel log_level_ = INFO;
};