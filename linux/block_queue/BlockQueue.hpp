#pragma once

#include <iostream>
#include <queue>
#include <pthread.h>

template <typename T>
class BlockQueue
{
    static const int defaultNumber = 10;
public:
    BlockQueue(int capacity = defaultNumber) : capacity_(capacity)
    {
        // 初始化
        pthread_mutex_init(&mutex_, nullptr);
        pthread_cond_init(&p_cond_, nullptr);
        pthread_cond_init(&c_cond_, nullptr);
    }
    void push(const T &data)
    {
        pthread_mutex_lock(&mutex_);
        if (q_.size() == capacity_)
        {
            // 释放锁
            pthread_cond_wait(&p_cond_, &mutex_);
        }
        // 队列没满
        q_.push(data);
        pthread_cond_signal(&c_cond_);
        pthread_mutex_unlock(&mutex_);
    }
    T pop()
    {
        pthread_mutex_lock(&mutex_);
        if (q_.size() == 0)
        {
            pthread_cond_wait(&c_cond_, &mutex_);
        }
        T data = q_.front();
        q_.pop();
        pthread_cond_signal(&p_cond_);
        pthread_mutex_unlock(&mutex_);
        return data;
    }
    ~BlockQueue()
    {
        pthread_mutex_destroy(&mutex_);
        pthread_cond_destroy(&p_cond_);
        pthread_cond_destroy(&c_cond_);
    }
private:
    std::queue<T> q_; // 队列
    int capacity_; // 极值
    pthread_mutex_t mutex_; // 锁
    pthread_cond_t p_cond_; // 生产者同步
    pthread_cond_t c_cond_; // 消费者同步
};