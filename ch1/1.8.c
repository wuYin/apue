#include "apue.h"
#include <errno.h>

// 1.8 例示 strerror 和 perror
int main(int argc, char *argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES)); // 无权限错误
    errno = EACCES;                                    // 全局变量
    perror(argv[0]);
}