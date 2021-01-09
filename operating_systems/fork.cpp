#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, const char * argv[]) {
  pid_t pid;

  pid = fork();   // fork a child process

  if (pid < 0) {
    fprintf(stderr, "Fork failed\n");
    return 1;
  } else if (pid == 0) {
    execlp("/bin/ls", "ls", NULL);    // child process

    printf("these lines of code will never be run!\n");
    printf("    because execlp(...) completely replaces the child's code\n");
    printf("    with its own code\n");
  } else {   // parent process
    printf("the child's pid: %d, and parent's pid: %d\n\n", pid, getpid());
    wait(NULL);
    printf("************************************* Child complete\n");
  }

  printf("Parent complete\n\n");
  return 0;
}
