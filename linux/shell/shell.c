#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>

#define LEFT "["
#define RIGHT "]"
#define SYMBOL "#"
#define MAX_SIZE 1024
#define ARGC_SIZE 32
#define DELIM " \t"
#define EXIT_CODE 60
#define NONE -1
#define IN_RDIR 0
#define OUT_RDIR 1
#define APPEND_RDIR 2

int last_exit_code = 0;
char my_env[ARGC_SIZE];
char *rdir_filename = NULL;
int rdir_no = NONE;

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
  char pwd[MAX_SIZE];
  char *ret = getcwd(pwd, sizeof(pwd));
  return ret;
}

void check_rdir(char *command_line)
{
  char *cur = command_line;
  while (*cur)
  {
    if (*cur == '>')
    {
      if (*(cur + 1) == '>')
      {
        // 追加重定向
        *cur++ = '\0';
        *cur++ = '\0';
        while (isspace(*cur))
        {
          cur++;
        }
        rdir_filename = cur;
        rdir_no = APPEND_RDIR;
        break;
      }
      else 
      {
        // 输出重定向
        *cur = '\0';
        cur++;
        while (isspace(*cur))
        {
          cur++;
        }
        rdir_filename = cur;
        rdir_no = OUT_RDIR;
        break;
      }
    }
    else if (*cur == '<')
    {
      // 输入重定向
      *cur = '\0';
      cur++;
      while (isspace(*cur))
      {
        // 移除空格
        cur++;
      }
      rdir_filename = cur;
      rdir_no = IN_RDIR;
      break;
    }
    else 
    {
      // nothing to do
    }
    cur++;
  }
}

void mutual(char *command_line, int size)
{
  printf(LEFT"%s@%s %s"RIGHT""SYMBOL" ", get_user(), get_hostname(), get_pwd());
  char *s = fgets(command_line, size, stdin);
  (void)s;
  command_line[strlen(command_line) - 1] = '\0';

  check_rdir(command_line);
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
      // 解决重定向问题
      int fd = 0;
      if (rdir_no == IN_RDIR)
      {
        fd = open(rdir_filename, O_RDONLY);
        dup2(fd, 0);
      }
      else if (rdir_no == OUT_RDIR)
      {
        fd = open(rdir_filename, O_CREAT|O_WRONLY|O_TRUNC, 0666);
        dup2(fd, 1);
      }
      else if (rdir_no == APPEND_RDIR)
      {
        fd = open(rdir_filename, O_CREAT|O_WRONLY|O_APPEND, 0666);
        dup2(fd, 1);
      }
      execvp(argv[0], argv);
      exit(EXIT_CODE);
    }
    else 
    {
      // 父进程，等待子进程
      int status = 0;
      pid_t rid = waitpid(id, &status, 0); // 阻塞等待
      if (rid == id)
      {
        // 等待成功
        last_exit_code = WEXITSTATUS(status);
      }
    }
}

int build_in_commands(int argc, char **argv)
{
  if (argc == 2 && strcmp(argv[0], "cd") == 0)
  {
    // cd命令
    chdir(argv[1]);
    sprintf(getenv("PWD"), "%s", get_pwd());
    return 1;
  }
  else if (argc == 2 && strcmp(argv[0], "export") == 0)
  {
    // export命令，导入环境变量
    strcpy(my_env, argv[1]);
    putenv(my_env);
    return 1;
  }
  else if (argc == 2 && strcmp(argv[0], "echo") == 0)
  {
    // echo命令
    if (strcmp(argv[1], "$?") == 0)
    {
      printf("%d\n", last_exit_code);
      last_exit_code = 0;
    }
    else if (*argv[1] == '$')
    {
      // 打印环境变量
      char *ret = getenv(argv[1] + 1);
      if (ret) printf("%s\n", ret);
    }
    else 
    {
      printf("%s\n", argv[1]);
    }
    return 1;
  }
  if (strcmp(argv[0], "ls") == 0)
  {
    argv[argc++] = "--color";
    argv[argc] = NULL;
  }
  return 0;
}

int main()
{
  char command_line[MAX_SIZE];
  char *argv[ARGC_SIZE];
  int quit = 0;
  while (!quit)
  {
    // 1. 设置重定向相关参数
    rdir_filename = NULL;
    rdir_no = NONE;
    // 2. 获取命令行
    mutual(command_line, sizeof(command_line));
    // printf("%s", command_line);
    
    // 3. 分割字符串
    int argc = splite_string(command_line, argv);
    if (argc == 0) continue;
    //for (int j = 0; j < i; j++)
    //{
    //  printf("[%d]: %s\n", j, argv[j]);
    //}
    

    // 4. 内建命令
    int n = build_in_commands(argc, argv);    
    // 5. 普通命令
    if (!n) execute_command(argv);
  }
  return 0;
}
