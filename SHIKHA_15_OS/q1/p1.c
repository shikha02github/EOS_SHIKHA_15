#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
    int fd=0;
    fd=open("user/include/stdio.h",O_WRONLY);
    write(fd,"shikha\n",10);
    close(fd);
    return 0;
}