#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>

#define SIZE_OF_BUFF 30

int main(int argc, char *argv[])
{
    char buffer_input[SIZE_OF_BUFF];
    char cwd[512];
    size_t s = 4;
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;

    char buf[512];

    while (1)
    {
        puts("yes boss?");

        fgets(buffer_input, SIZE_OF_BUFF, stdin);
        if (strncmp(buffer_input, "EXIT", s) == 0)
        {
            break;
        }
        if (strncmp(buffer_input, "ECHO", s) == 0)
        {
            printf("%s\n", buffer_input + 5);
        }
        if ((strncmp(buffer_input, "DIR", 3) == 0))
        {
            mydir = opendir(argv[1]); //THROW ERROR..
            while ((myfile = readdir(mydir)) != NULL)
            {
                sprintf(buf, "%s/%s", argv[1], myfile->d_name);
                stat(buf, &mystat);
                printf("%zu", mystat.st_size);
                printf(" %s\n", myfile->d_name);
            }
            closedir(mydir);
        }
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            printf("Current working dir: %s\n", cwd);
        }
        else
        {
            perror("getcwd() error");
            break;
        }
    }

    printf("by");
    return 0;
}
