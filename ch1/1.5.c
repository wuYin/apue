#include "apue.h"

// 1.5 读取标准输入并写回标准输出
int main()
{
    int c;
    while ((c = getc(stdin)) != EOF)   // 从标准输入读取后直接写回标准输出
        while (putc(c, stdout) != EOF) // 标准 IO 无需指定缓冲区大小
            err_sys("putc error");

    if (ferror(stdin))
        err_sys("input error");

    return 0;
}