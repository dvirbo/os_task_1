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
        // 1
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
            servaddr.sin_port = htons(8080);

            // connect the client socket to server socket
            int sockTT = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
            dup2(1, 123);
            dup2(sockfd, 1);
        }
        else if (strncmp("LOCAL", msg, 5) == 0)
        {
            dup2(123, 1);
            /// priny
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

        // 9
        //  else if (/* condition */)
        //  {
        //      /* code */
        //  }

        // 10
        //  else if (/* condition */)
        //  {
        //      /* code */
        //  }

        // 8
        //  else
        //  {
        //      system(buffer_input); // g implement with sys..
        //  }
    }
    return 0;
}