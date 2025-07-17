#pragma once

#include <iostream>
#include <pthread.h>
#include <vector>
#include <queue>
#include <string>

struct ThreadInfo
{
    pthread_t tid;
    std::string name;
};

static const int defaultNumber = 5;

template<typename T>
class ThreadPool
{
    // 封装加锁
    void lock()
    {
        pthread_mutex_lock(&mutex_);
    }
    void unlock()
    {
        pthread_mutex_unlock(&mutex_);
    }
    void wakeUp()
    {
        pthread_cond_signal(&cond_);
    }
    void threadSleep()
    {
        pthread_cond_wait(&cond_, &mutex_);
    }
    bool isEmpty()
    {
        return task_.empty();
    }
    std::string getName(pthread_t id)
    {
        for (const auto &i : threadPool_)
        {
            if (i.tid == id) return i.name;
        }
        return "";
    }
public:
    ThreadPool(int capacity = defaultNumber) 
    : threadPool_(capacity)
    {
        pthread_mutex_init(&mutex_, nullptr);
        pthread_cond_init(&cond_, nullptr);
    }
    static void *handlerTask(void *args)
    {
        ThreadPool<T> *tp = static_cast<ThreadPool<T> *>(args);
        std::string name = tp->getName(pthread_self());
        while (true)
        {
            tp->lock();

            while (tp->isEmpty())
            {
                tp->threadSleep();
            }
            T t = tp->pop();
            tp->unlock();

            t.run();
            std::cout << name << " get a task, calculate done. " << t.printResult() << std::endl;
        }
    }
    void start()
    {
        int num = threadPool_.size();
        for (int i = 0; i < num; i++)
        {
            // 创建线程
            threadPool_[i].name = "thread->" + std::to_string(i + 1);
            pthread_create(&(threadPool_[i].tid), nullptr, handlerTask, this);
        }
    }
    void push(const T &task)
    {
        lock();
        task_.push(task);
        wakeUp();
        unlock();
    }
    T pop()
    {
        T t = task_.front();
        task_.pop();
        return t;
    }
    ~ThreadPool()
    {
        pthread_mutex_destroy(&mutex_);
        pthread_cond_destroy(&cond_);
    }
private:
    std::vector<ThreadInfo> threadPool_; // 线程池数组
    std::queue<T> task_; // 任务队列

    pthread_mutex_t mutex_; // 线程锁
    pthread_cond_t cond_; // 线程条件变量
};