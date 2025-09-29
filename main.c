#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_COUNT 5

int main(void) {
    pid_t pid;
    int i;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    for (i = 1; i <= MAX_COUNT; i++) {
        char buffer[100];
        int n = snprintf(buffer, sizeof(buffer),
                         "This line is from pid %d, value %d\n",
                         getpid(), i);
        write(STDOUT_FILENO, buffer, n);
    }

    return 0;
}

