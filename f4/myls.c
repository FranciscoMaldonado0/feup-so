#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

void printLs(char filename[])
{
    struct stat fileStat;
    if (stat(filename, &fileStat) < 0)
        return 1;

    printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf(" %d ", fileStat.st_nlink);
    struct passwd *pws;
    pws = getpwuid(fileStat.st_uid);
    printf("%s ",pws->pw_name);
    struct group *grp;
    grp = getgrgid(fileStat.st_gid);
    printf("%s ", grp->gr_name);
    printf("%d ", fileStat.st_size);
    char *str = malloc(12);
    strncpy(str,ctime(&fileStat.st_mtim.tv_sec) + 4, 12);
    str[12] = '\0';
    str[0] = tolower(str[0]);
    printf("%s ", str);
    printf("%s\n", filename);

    // printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
}
int main(int argc, char **argv)
{

    int len;
    struct dirent *p;
    DIR *q;
    if (argc != 2)
    {
        fprintf(stderr, "usage: %s dirname\n", argv[0]);
        return EXIT_FAILURE;
    }
    q = opendir(argv[1]);
    if (q == NULL)
    {
        struct stat fileStat;
        if (stat(argv[1], &fileStat) < 0)
        {
            fprintf(stderr, "%s: Cannot open directory '%s'\n",
                    argv[0], argv[1]);
            return EXIT_FAILURE;
        }
        printLs(argv[1]);
        return EXIT_SUCCESS;
    }
    printf("%s/\n", argv[1]);
    p = readdir(q);
    while (p != NULL)
    {
        printLs(p->d_name);
        p = readdir(q);
    }
    closedir(q);
    return EXIT_SUCCESS;
}