#pragma once

#include <iostream>
#include <semaphore.h>
#include <vector>

template<typename T>
class RingQueue
{
    static const int default_number = 5;
    void P(sem_t &sem)
    {
        sem_wait(&sem);
    }
    void V(sem_t &sem)
    {
        sem_post(&sem);
    }
public:
    RingQueue(int capacity = default_number) : q_(capacity), capacity_(capacity), p_pos_(0), c_pos_(0)
    {
        sem_init(&p_space_, 0, default_number);
        sem_init(&c_space_, 0, 0);
    }
    void push(const T &data)
    {
        P(p_space_);
        q_[p_pos_] = data;
        p_pos_++;
        p_pos_ %= capacity_;
        V(c_space_);
    }
    void pop(T *data)
    {
        P(c_space_);
        *data = q_[c_pos_];
        c_pos_++;
        c_pos_ %= capacity_;
        V(p_space_);
    }
    ~RingQueue()
    {
        sem_destroy(&p_space_);
        sem_destroy(&c_space_);
    }
private:
    std::vector<T> q_; // 环形队列
    int capacity_; // 容量
    int p_pos_; // 生产者下标
    int c_pos_; // 消费者下标

    sem_t p_space_; // 生产者数据量
    sem_t c_space_; // 消费者消费数
};