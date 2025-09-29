#include <stdio.h>
#include <stdlib.h>     // For srandom(), random(), exit()
#include <unistd.h>     // For getpid(), getppid(), fork(), sleep()
#include <sys/types.h>  // For pid_t
#include <sys/wait.h>   // For wait()
#include <time.h>       // For time()

#define MAX_ITER 30     // Maximum number of iterations
#define MAX_SLEEP 10    // Maximum sleep time in seconds

void child_process(void) {
    pid_t pid = getpid();
    pid_t ppid = getppid();

    srandom(time(NULL) ^ pid);  // Seed random generator with time XOR pid
    int iterations = random() % MAX_ITER + 1;

    for (int i = 0; i < iterations; i++) {
        printf("Child Pid: %d is going to sleep!\n", pid);
        sleep(random() % MAX_SLEEP + 1);  // Sleep random 1-10 seconds
        printf("Child Pid: %d is awake! Where is my Parent: %d?\n", pid, ppid);
    }

    exit(0); // Terminate child
}

int main(void) {
    pid_t child1, child2;
    int status;

    child1 = fork();
    if (child1 < 0) {
        perror("fork failed");
        exit(1);
    } else if (child1 == 0) {
        child_process();
    }

    child2 = fork();
    if (child2 < 0) {
        perror("fork failed");
        exit(1);
    } else if (child2 == 0) {
        child_process();
    }

    // Parent waits for both children
    pid_t wpid;
    while ((wpid = wait(&status)) > 0) {
        printf("Child Pid: %d has completed\n", wpid);
    }

    return 0;
}

