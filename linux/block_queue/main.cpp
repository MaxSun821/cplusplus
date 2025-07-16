#include "BlockQueue.hpp"
#include "Task.hpp"
#include <unistd.h>
#include <ctime>

static const std::string opers = "+-*/%";

void *Productor(void *args)
{
    BlockQueue<Task> *bq = static_cast<BlockQueue<Task> *>(args);
    // 生产者生产数据
    int size = opers.size();
    while (true)
    {
        int data1 = rand() % 10 + 1;
        int data2 = rand() % 10 + 1;
        char oper = opers[rand() % size];

        Task t(data1, data2, oper);

        bq->push(t);
        sleep(1);
    }
    return nullptr;
}

void *Consumer(void *args)
{
    BlockQueue<Task> *bq = static_cast<BlockQueue<Task> *>(args);
    // 消费者
    while (true)
    {
        Task t = bq->pop();
        std::cout << "消费者拿到一个数据: " << std::endl;
        t.run();
        std::cout << t.printResult() << std::endl;
        sleep(2); 
    }
    return nullptr;
}

int main()
{
    srand(time(nullptr));
    BlockQueue<Task> *bq = new BlockQueue<Task>();

    pthread_t p, c;

    pthread_create(&p, nullptr, Productor, bq);
    pthread_create(&c, nullptr, Consumer, bq);

    pthread_join(p, nullptr);
    pthread_join(c, nullptr);

    delete bq;

    return 0;
}