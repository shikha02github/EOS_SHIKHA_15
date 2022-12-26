#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int fd;
    char read_msg[25];
    fd=open("user/include/stdio.h",O_RDONLY);
    read(fd,read_msg,25);
    printf("read=%s",read_msg);
    close(fd);
    return 0;

}