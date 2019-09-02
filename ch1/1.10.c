#include "apue.h"
#include <sys/wait.h>

static void onSigInterupt(int);

// 1.10 捕捉中断信号
int main()
{
    char buf[MAXLINE]; // 4KB
    pid_t pid;
    int status;

    if (signal(SIGINT, onSigInterupt) == SIG_ERR)
        err_sys("signal failed");

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

        // 父进程
        if ((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("wait failed");

        printf("%% ");
    }
}

void onSigInterupt(int signo)
{
    printf("interrupt\n");
}