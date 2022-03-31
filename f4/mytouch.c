#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <utime.h>
int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_CREAT);
    mode_t newperms = (mode_t)0;
    newperms |= S_IRUSR | S_IWUSR;
    newperms |= S_IRGRP;
    newperms |= S_IROTH;
    chmod(argv[1], newperms);
    
    utime(argv[1], NULL);

    close(fd);
}