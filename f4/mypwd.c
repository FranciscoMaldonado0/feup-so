#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{   
    char *buffer = malloc(1024 * sizeof(char));
    getcwd(buffer, 1024);
    printf("%s", buffer);
    return EXIT_SUCCESS;
}