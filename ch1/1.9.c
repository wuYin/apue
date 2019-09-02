#include "apue.h"

// 1.9 打印用户 ID 和组 ID
int main()
{
    printf("uid: %d, gid:%d\n", getuid(), getgid());
}