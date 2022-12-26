#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

struct mq_attr desd_mq_attr;

int main()
{
    mqd_t fd = 0; //message queue descriptor
    int err = 0;
    int err_send = 0;
    int err_cl = 0;
    desd_mq_attr.mq_flags = 0;
    desd_mq_attr.mq_maxmsg = 4;
    desd_mq_attr.mq_msgsize = 64;
    desd_mq_attr.mq_curmsgs = 0;
    
    fd = mq_open("/desd_mq", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR, &desd_mq_attr);
    if(fd == -1)
    {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    err_send = mq_send(fd, "Hello from sender\n",strlen("Hello from sender\n"), 0);
    if(err_send == -1)
    {
        perror("mq_send");
        exit(EXIT_FAILURE);
    }

    err_cl = mq_close(fd);
    if(err_cl == -1)
    {
        perror("mq_close");
        exit(EXIT_FAILURE);
    }

    return 0;
}