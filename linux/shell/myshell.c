#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

#define LEFT "["
#define RIGHT "]"
#define SYMBOL "#"
#define MAX_SIZE 1024
#define ARGC_SIZE 32
#define DELIM " \t"
#define EXIT_CODE 60

const char *get_user()
{
  return getenv("USER");
}

const char *get_hostname()
{
  return getenv("HOSTNAME");
}

const char *get_pwd()
{
  return getenv("PWD");
}



void mutual(char *command_line, int size)
{
  printf(LEFT"%s@%s %s"RIGHT""SYMBOL" ", get_user(), get_hostname(), get_pwd());
  char *s = fgets(command_line, size, stdin);
  (void)s;
  command_line[strlen(command_line) - 1] = '\0';
}

int splite_string(char *command_line, char **argv)
{
    int i = 0;
    argv[i++] = strtok(command_line, DELIM);
    while (argv[i++] = strtok(NULL, DELIM));
    return i - 1;
}

void execute_command(char **argv)
{
    extern char **environ;
    pid_t id = fork();
    if (id < 0)
    {
      perror("fork");
    }
    else if (id == 0)
    {
      // 子进程，执行普通命令
      execvpe(argv[0], argv, environ);
      exit(EXIT_CODE);
    }
    else 
    {
      // 父进程，等待子进程
      int status = 0;
      int last_exit_code = 0;
      pid_t rid = waitpid(id, &status, 0); // 阻塞等待
      if (rid == id)
      {
        // 等待成功
        last_exit_code = WEXITSTATUS(status);
      }
    }
}

int main()
{
  char command_line[MAX_SIZE];
  char *argv[ARGC_SIZE];
  int quit = 0;
  while (!quit)
  {
    // 1. 获取命令行
    mutual(command_line, sizeof(command_line));
    // printf("%s", command_line);
    
    // 2. 分割字符串
    int i = splite_string(command_line, argv);
    //for (int j = 0; j < i; j++)
    //{
    //  printf("[%d]: %s\n", j, argv[j]);
    //}
    
    // 3. 判断命令
    

    // 4. 内建命令
    
    // 5. 普通命令
    execute_command(argv);
  }
  return 0;
}
