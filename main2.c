#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_COUNT 10

void ChildProcess(void);
void ParentProcess(void);

int main(void) {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0) {
        ChildProcess();
    } else {
        ParentProcess();
    }

    return 0;
}

void ChildProcess(void) {
    int i;
    for (i = 1; i <= MAX_COUNT; i++) {
        printf("   This line is from CHILD, value = %d\n", i);
        usleep(100000);
    }
}

void ParentProcess(void) {
    int i;
    for (i = 1; i <= MAX_COUNT; i++) {
        printf("This line is from PARENT, value = %d\n", i);
        usleep(100000);
    }
}


