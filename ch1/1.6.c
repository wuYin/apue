#include "apue.h"

// 1.6 打印进程 id
int main()
{
    printf("hello world from pid: %ld\n", (long)getpid());
    return 0;
}