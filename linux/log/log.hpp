#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdarg>     // va_list
#include <cstdio>      // vsnprintf

#ifdef _WIN32
    #include <direct.h>
    #define MKDIR(dir) _mkdir(dir)
#else
    #include <sys/stat.h>
    #define MKDIR(dir) mkdir(dir, 0755)
#endif

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
    Logger(const std::string &dir = "log") : log_dir_(dir)
    {
        // 创建目录
        if (MKDIR(log_dir_.c_str()) != 0) {}
        // 初始化日志文件流，每个级别对应一个文件
        info_file_.open(dir + "/info.log", std::ios::app);
        warning_file_.open(dir + "/warning.log", std::ios::app);
        error_file_.open(dir + "/error.log", std::ios::app);
        fatal_file_.open(dir + "/fatal.log", std::ios::app);
        debug_file_.open(dir + "/debug.log", std::ios::app);

        if (!(info_file_ && warning_file_ && error_file_ && fatal_file_ && debug_file_))
        {
            std::cerr << "无法打开日志文件" << std::endl;
        }
    }

    // 析构函数，关闭文件
    ~Logger()
    {
        if (info_file_.is_open()) info_file_.close();
        if (warning_file_.is_open()) warning_file_.close();
        if (error_file_.is_open()) error_file_.close();
        if (fatal_file_.is_open()) fatal_file_.close();
        if (debug_file_.is_open()) debug_file_.close();
    }

    // 设置日志级别
    void setLogLevel(LogLevel level)
    {
        log_level_ = level;
    }

    // 输出日志
    void log(LogLevel level, const char* format, ...)
    {
        if (level < log_level_) return;

        char message[1024];  // 临时缓冲区
        va_list args;
        va_start(args, format);
        vsnprintf(message, sizeof(message), format, args);
        va_end(args);

        std::string timestamp = getCurrentTime();
        std::string level_str = logLevelToString(level);
        std::ofstream* target_file = getLogFile(level);

        if (target_file && target_file->is_open()) {
            *target_file << "[" << timestamp << "] [" << level_str << "] " << message << std::endl;
        }

        std::cout << "[" << timestamp << "] [" << level_str << "] " << message << std::endl;
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

    std::ofstream *getLogFile(LogLevel level)
    {
        switch (level) 
        {
            case INFO:    return &info_file_;
            case WARNING: return &warning_file_;
            case ERROR:   return &error_file_;
            case FATAL:   return &fatal_file_;
            case DEBUG:   return &debug_file_;
            default:      return nullptr;
        }
    }

    std::string log_dir_;
    // std::ofstream log_file_; // 日志文件流
    std::ofstream info_file_;
    std::ofstream warning_file_;
    std::ofstream error_file_;
    std::ofstream fatal_file_;
    std::ofstream debug_file_;

    LogLevel log_level_ = INFO;
};