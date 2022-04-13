#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <netinet/in.h> //structure for storing address information
#include <sys/socket.h> //for socket APIs
#include <sys/types.h>


int main()
{
    char msg[1024];
    char cwd[256];

    while (1)
    {
        //  1
        puts("yes boss?");
        fgets(msg, sizeof(msg), stdin);
        msg[strlen(msg) - 1] = '\0';
        if (strncmp("EXIT", msg, 4) == 0)
        {
            puts("by");
            return 0;
        }

        // 2 PROMPT
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            printf("Current working dir: %s\n", cwd);
        }
        else
        {
            break;
        }

        // 3
        if (strncmp("ECHO", msg, 4) == 0)

        {
            char *r = msg + 5;
            printf("%s \n", r);
        }

        // 4
        else if (strncmp("TCP PORT", msg, 8) == 0)
        {

            // connect to server

            int sockfd, connfd;

            struct sockaddr_in servaddr, cli;

            // socket create and verification

            sockfd = socket(AF_INET, SOCK_STREAM, 0);

            if (sockfd == -1)
            {

                printf("socket creation failed...\n");

                exit(0);
            }

            else

                printf("Socket successfully created..\n");

            bzero(&servaddr, sizeof(servaddr));

            // assign IP, PORT

            servaddr.sin_family = AF_INET;

            servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

            servaddr.sin_port = htons(8888);

            // connect the client socket to server socket

            int sockTT = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

            dup2(1, 123);

            dup2(sockfd, 1);
        }

        // 5
        else if (strncmp("LOCAL", msg, 5) == 0)
        {
            dup2(123, 1);
            /// print
        }

        // 6
        else if (strncmp("DIR", msg, 3) == 0)
        {
            DIR *d;
            struct dirent *dir;
            d = opendir(".");
            if (d)
            {
                while ((dir = readdir(d)) != NULL)
                {
                    printf("%s\n", dir->d_name);
                }
                closedir(d);
                printf("\n");
            }
        }

        // 7
        else if (strncmp("CD", msg, 2) == 0)
        {
            char *str = msg + 3;
            if (chdir(str) != 0)
            {
                perror("chdir() failed");
            }
        }

        // 8
        // else
        // {
        //     system(msg); //  implement with sys..
        // }

        // 10
        else if (strncmp("COPY", msg, 4) == 0)
        {
            char c;
            char src[15];
            char dest[15];
            char *tmp = msg + 5;
            int isrc = 0;
            while (msg[isrc] != ' ')
            {
                isrc++;
            }
            isrc++; // length of the src
            char *tmp2 = tmp + isrc + 1;
            int idest = strlen(tmp2); // //LENGTH of the dest
            memset(src, '\0', sizeof(src));
            memset(dest, '\0', sizeof(dest));
            strncpy(src, tmp, isrc);
            strncpy(dest, tmp2, idest);
            FILE *from, *to;
            from = fopen(src, "r");
            if (from == NULL)
            {
                exit(EXIT_FAILURE);
            }
            to = fopen(dest, "w");
            if (to == NULL)
            {
                fclose(from);
                printf("Press any key to exit...\n");
                exit(EXIT_FAILURE);
            }
            while ((c = fgetc(from)) != EOF)
            {
                fputc(c, to);
            }
            printf("File copied successfully.\n");
            fclose(from);
            fclose(to);
        }

        else if (strncmp("DELETE", msg, 6) == 0)
        {
            char name[15];
            char *tmp = msg + 7;
            if (unlink(tmp) != 0)
            {
                printf(" unlink() failed");
            }
        }

        else
        {

            pid_t pid = fork();
            if (pid < 0)
            {
                perror("fork() faild..");
                exit(EXIT_FAILURE);
            }
            else if (pid == 0)
            {
                char **res = NULL;
                char *p = strtok(msg, " ");
                int n_spaces = 0, i;

                /* split string and append tokens to 'res' */

                while (p)
                {
                    res = realloc(res, sizeof(char *) * ++n_spaces);

                    if (res == NULL)
                        exit(-1); /* memory allocation failed */

                    res[n_spaces - 1] = p;

                    p = strtok(NULL, " ");
                }

                /* realloc one extra element for the last NULL */

                res = realloc(res, sizeof(char *) * (n_spaces + 1));
                res[n_spaces] = 0;

                execvp(res[0], res);
                /* free the memory allocated */

                free(res);
                continue;
            }
            wait(NULL);
        }
    }
    return 0;
}
/*
ans:
The chdir command is a system call
system is library function
COPY implemented by using library function such as fopen() but we also using exit() that is a system calls..
DELETE using unlink that is a system call


bibliography:
9: https://stackoverflow.com/questions/11198604/c-split-string-into-an-array-of-strings
*/