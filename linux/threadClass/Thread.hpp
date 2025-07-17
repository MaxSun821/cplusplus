#pragma once

#include <pthread.h>
#include <string>
#include <functional>
#include <ctime>

static int num = 0;

class Thread
{
public:
    Thread(std::function<void()> cb) 
    : tid_(0), name_(""), start_timestamp_(0), isRunning_(false), cb_(cb)
    {}
    ~Thread() {}
    static void *routine(void *args)
    {
        Thread *t = static_cast<Thread *>(args);
        t->cb_();
        return nullptr;
    }
    void run()
    {
        name_ = "thread->" + std::to_string(num++);
        start_timestamp_ = time(nullptr);
        isRunning_ = true;
        pthread_create(&tid_, nullptr, routine, this);
    }
    void join()
    {
        pthread_join(tid_, nullptr);
        isRunning_ = false;
    }
    std::string getName()
    {
        return name_;
    }
    bool isRunning()
    {
        return isRunning_;
    }
private:
    pthread_t tid_;
    std::string name_;
    uint64_t start_timestamp_; //启动时间戳
    bool isRunning_;

    std::function<void()> cb_;
};