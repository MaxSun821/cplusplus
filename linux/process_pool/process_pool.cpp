#include "tasks.hpp"



const int process_num = 10;
std::vector<task_t> tasks;

class channel
{
public:
    channel(int cmdfd, pid_t workerid, std::string &name)
        : _cmdfd(cmdfd), _workerid(workerid), _name(name)
    {}

public:
    int _cmdfd;        // 发送任务的文件描述符
    pid_t _workerid;   // 子进程pid
    std::string _name; // 子进程名字
};

void init_process_pool(std::vector<channel>* channels);
void worker(void);
void ctrl_worker(const std::vector<channel>& channels);
void debug(const std::vector<channel>& channels);
void quit_process(const std::vector<channel>& channels);

int main()
{
    
    // Load Tasks
    load_tasks(&tasks);

    std::vector<channel> channels;
    
    // 初始化进程池
    init_process_pool(&channels);

    ctrl_worker(channels);
    // 测试
    // debug(channels);

    // clear process
    quit_process(channels);

    std::cout << "main quit" << std::endl;

    return 0;
}


void init_process_pool(std::vector<channel>* channels)
{
    for(int i = 0; i < process_num; i++)
    {
        // 创建管道
        int pipefd[2];
        int n = pipe(pipefd);

        assert(!n);
        // 创建子进程
        pid_t id = fork();
        if(id == 0)
        {
            // child, read
            close(pipefd[1]); // close write
            dup2(pipefd[0], 0);
            close(pipefd[0]);
            worker();
            std::cout << "process pool exit" << std::endl;
            exit(0);
        }
        // father write
        close(pipefd[0]); // close read
        std::string name = "process pool: " + std::to_string(i);
        channels->push_back(channel(pipefd[1], id, name));
    }
}

void worker()
{
    while(true)
    {
        int cmdcode = 0;
        int n = read(0, &cmdcode, sizeof(int)); // 一次读4个字节
        if(n == sizeof(int))
        {
            // read success
            std::cout << "worker get a command: " << getpid() << ": cmdcode: " << cmdcode << std::endl;
            if(cmdcode >= 0 && cmdcode < tasks.size())
            {
                tasks[cmdcode]();
            }
        }
        if(n == 0)
        {
            // read file over
            break;
        }
    }
}

void ctrl_worker(const std::vector<channel>& channels)
{
    int count = 5;
    while(count)
    {
        // 选择任务
        int cmdcode = rand() % tasks.size();

        // 选择进程
        int process_pos = rand() % channels.size();

        std::cout << "master send to " << channels[process_pos]._workerid 
        << " a message what is " << cmdcode << " worker's name is " 
        << channels[process_pos]._name << std::endl;
        // 发送任务
        write(channels[process_pos]._cmdfd, &cmdcode, sizeof(cmdcode));
        count--;
        sleep(1);
    }
}

void debug(const std::vector<channel>& channels)
{
    for(auto& e : channels)
    {
        std::cout << e._cmdfd << " " << e._workerid << " " << e._name << std::endl;
    }
}

void quit_process(const std::vector<channel>& channels)
{
    for(const auto& e : channels)
    {
        close(e._cmdfd);
    }
    
    for(const auto& e : channels)
    {
        waitpid(e._workerid, nullptr, 0);
    }
}