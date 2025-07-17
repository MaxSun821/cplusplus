#include "RingQueue.hpp"
#include <pthread.h>
#include <ctime>
#include <unistd.h>


void *Productor(void *args)
{
    RingQueue<int> *rq = static_cast<RingQueue<int> *>(args);

    while (true)
    {
        int data = rand() % 10 + 1;
        std::cout << "生产者生产了一个数据: " << data << std::endl;
        rq->push(data);
        sleep(1);
    }

}

void *Consumer(void *args)
{
    RingQueue<int> *rq = static_cast<RingQueue<int> *>(args);

    while (true)
    {
        int data = 0;
        rq->pop(&data);
        std::cout << "消费者消费了一个数据: " << data << std::endl;
        sleep(3);
    }
}

int main()
{
    srand(time(nullptr));
    RingQueue<int> *rq = new RingQueue<int>();

    pthread_t p, c;

    pthread_create(&p, nullptr, Productor, rq);
    pthread_create(&c, nullptr, Consumer, rq);

    pthread_join(p, nullptr);
    pthread_join(c, nullptr);

    return 0;
}