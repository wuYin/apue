#include "apue.h"
#include <dirent.h>

// 1.3 列出指定目录下的所有文件
int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2)
        err_quit("usage: ls directory_name");

    if ((dp = opendir(argv[1])) == NULL) // 打开命令行参数 1 指定的目录
        err_sys("can't open %s", argv[1]);

    while ((dirp = readdir(dp)) != NULL) // 循环读取目录下文件
        printf("%s\n", dirp->d_name);    // 输出文件名

    closedir(dp); // 关闭文件句柄
    return 0;
}