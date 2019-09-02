#include "apue.h"
#include <sys/wait.h>

// 1.7 从标准输入读取命令并执行
int main()
{
    char buf[MAXLINE]; // 4KB
    pid_t pid;
    int status;

    printf("%% "); // % 自转义
    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0; // 手动截取整行作为命令

        if ((pid = fork()) < 0)
        {
            err_sys("fork failed");
        }
        else if (pid == 0)
        {
            execlp(buf, buf, (char *)0);
            err_ret("can't exec: %s", buf);
            exit(127);
        }

        // 父进程等待指定 pid 的子进程
        if ((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("wait failed");

        printf("%% ");
    }
}