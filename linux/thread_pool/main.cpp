#include "Task.hpp"
#include "ThreadPool.hpp"
#include <ctime>
#include <unistd.h>


int main()
{
    ThreadPool<Task> *tp = new ThreadPool<Task>();
    tp->start();
    srand(time(nullptr));

    while (true)
    {
        // 1. 构建任务
        int x = rand() % 10 + 1;
        int y = rand() % 10;
        char op = opers[rand() % opers.size()];

        Task t(x, y, op);
        tp->push(t);

        sleep(1);
    }
    return 0;
}