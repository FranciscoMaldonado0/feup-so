#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    struct stat info;
    if (argc < 2)
    {
        fprintf(stderr, "usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }
    int i = 1;
    int numBlocks = 0, numBytes = 0;
    while (i < argc)
    {
        if (lstat(argv[i], &info) == -1)
        {
            fprintf(stderr, "fsize: Can’t stat %s\n", argv[i]);
            return EXIT_FAILURE;
        }
        numBlocks += (int)info.st_blocks;
        numBytes += (int)info.st_size;
        printf("%s size: %d bytes, disk_blocks: %d mode:%x\n",
               argv[i], (int)info.st_size, (int)info.st_blocks, (int)info.st_mode);
        i++;
    }
    printf("Total size: %d bytes, disk_blocks: %d\n",numBytes, numBlocks);
    return EXIT_SUCCESS;
}