#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>


#define SIZE_OF_BUFF 30

int main() {
    char buffer_input[SIZE_OF_BUFF];
    char cwd[SIZE_OF_BUFF];
    size_t s = 4;

    while (1) {
        puts("yes boss?");

        fgets(buffer_input, SIZE_OF_BUFF, stdin);
        if (strncmp(buffer_input, "EXIT",s) == 0) //A
         { 
            break;
        } 
        if (getcwd(cwd, sizeof(cwd)) != NULL) { // b
            printf("Current working dir: %s\n", cwd);
        } else {
            perror("getcwd() error");
            break;

        }
        if (strncmp(buffer_input, "ECHO", s) == 0) { //C
            printf("%s\n", buffer_input + 5);
        }
        //     if((trcmp(buffer_input, "TCP PORT") == 0){ //d

        // }
    // ECHO HAIDE MACCABI YAFO
    }
    printf("by");
    return 0;
}