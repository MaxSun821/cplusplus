#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <sys/wait.h>
#include <sys/stat.h>

typedef void (*task_t)();

void task1()
{
    std::cout << "This is task 1, what I need to log a message" << std::endl;
}
void task2()
{
    std::cout << "This is task 2, what remember me something" << std::endl;
}
void task3()
{
    std::cout << "This is task 3, what show me something" << std::endl;
}
void task4()
{
    std::cout << "This is task 4, loading some messages" << std::endl;
}

void load_tasks(std::vector<task_t>* tasks)
{
    tasks->push_back(task1);
    tasks->push_back(task2);
    tasks->push_back(task3);
    tasks->push_back(task4);
}