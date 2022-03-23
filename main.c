#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>

#define SIZE_OF_BUFF 80

int main()
{
    char buffer_input[SIZE_OF_BUFF];
    char cwd[SIZE_OF_BUFF];
    size_t s3 = 3;
    DIR *d;
    struct dirent *dir;
    size_t s4 = 4;

    while (1)
    {
        puts("yes boss?");

        fgets(buffer_input, SIZE_OF_BUFF, stdin);
        if (strncmp(buffer_input, "EXIT", s4) == 0) // A
        {
            break;
        }
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        { // b
            printf("Current working dir: %s\n", cwd);
        }
        else
        {
            perror("getcwd() error");
            break;
        }
        if (strncmp(buffer_input, "ECHO", s4) == 0)
        { // C
            printf("%s\n", buffer_input + 5);
        }
        if ((strncmp(buffer_input, "DIR", s3) == 0))
        { // d
            printf("check dir");
            d = opendir(".");
            if (d)
            {
                while ((dir = readdir(d)) != NULL)
                {
                    printf("%s\n", dir->d_name);
                }
                closedir(d);
            }
        }
    }
    printf("by\n");
    return 0;
}
