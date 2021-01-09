// Gage Dimapindan CWID: 888017746
// CPSC 351-01, Fall 2020 Midterm

#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define BUFFER_SIZE  25
#define READ_END      0
#define WRITE_END     1

void write_child(char* write_msg, int* fd) {    // TODO
  printf("in parent\n");

  char write_msg[BUFFER_SIZE];
  for (int i = fd; i >= 0; i--) {
    printf("this line is to child.\n");
  }

}
void read_parent(char* read_msg, int* fd) {   // TODO
    printf("in child ---\n");

    char read_msg[BUFFER_SIZE];
    for (int i = fd; i >= 0; i--) {
      printf("this line is from parent.\n");
    }
}

int value = 5;
int main(int argc, const char * argv[]) {
  char write_msg[BUFFER_SIZE] = "have a happy Halloween!", char read_msg[BUFFER_SIZE];
  int fd[2];
  pid_t pid;
  if (pipe(fd) == -1) { fprintf(stderr, "pipe failed");  return 1; }
  pid = fork();                        // fork a child process
  if (pid < 0) {        fprintf(stderr, "fork failed");  return 1;    // fork failed
  } else if (pid > 0) { write_child(write_msg, fd);   // parent process
  } else {              value += 15;  wait(NULL);  printf("PARENT: value = %d\n\n", value);
                        read_parent(read_msg, fd);         // child process
  }
  return 0;
}
// in parent                                     // EXPECTED OUTPUT
//   writing "have a happy Halloween!" to child --------------
// closing parent
//		...done.
// PARENT: value = 20
// in child ---
//      reading "have a happy Halloween!" from parent ---
// closing child ---
