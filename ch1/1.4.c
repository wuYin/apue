#include "apue.h"

#define BUFFSIZE 4096 // 4kb

// 1.4 读取标准输入并写回标准输出
int main()
{
    int n;
    char buf[BUFFSIZE];

    // read/write 直接使用文件描述符，IO 不带缓冲，需自己指定缓冲区大小
    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) // 从标准输入 stdin 中读取 4KB 数据到 buf 字节数组中
        if (write(STDOUT_FILENO, buf, n) != n)          // 读取 n 个字节到 buf
            err_sys("write error");

    if (n < 0)
        err_sys("read error");

    return 0;
}