//
// dynamic threads doing work

// Gage Dimapindan, CWID: 888017746
// CPSC 351-01, Fall 2020 Midterm

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *runner(void *param) {
  // TODO: calculate sum from 1 to n (*param), return sum in *param

  int n = *(int*)param; // dereference passed in void* param
  int sum = 0;
  for (int i = 0; i <= n; ++i) {
    sum += i;
  }

  *(int*)param = sum;   // store answer in passed void* param

  pthread_exit(0);
}

void run_threads(int nthreads, pthread_attr_t attr) {
  // TODO: create nthreads threads, calculate the sum from 1 to N
  //       for each thread (a different number for each thread)
  //       run the threads, print out their sums, and free their memory
  //       (you will probably need memory for the sums too)

  pthread_t* tid = (pthread_t*)malloc(nthreads * sizeof(pthread_t));
  int *sums = (int*)malloc(nthreads * sizeof(int));

  memset(tid, 0, nthreads * sizeof(pthread_t));
  memset(sums, 0, nthreads * sizeof(int));

  for (int i = 0; i < nthreads; i++) {
    sums[i] = (i + 1) * 10;
    pthread_create(&tid[i], &attr, runner, &sums[i]);
  }

  printf("\n-----------------------------------\n");

  for (int i = 0; i < nthreads; i++) {
    pthread_join(tid[i], NULL);
    printf("thread %d's value: %d\n", i, sums[i]);
    if (i % 5 == 4 && i != nthreads - 1) {
      printf("\n");
    }
  }

  printf("\n-----------------------------------\n");

  free(tid);
  free(sums);

}

void setFIFO_run_threads(int nthreads) {
  pthread_attr_t attr;      // set scheduling policy to FIFO  and run nthreads
                            // TODO
  int policy;
  pthread_attr_init(&attr);     // get the default attributes

  pthread_attr_setschedpolicy(&attr, SCHED_FIFO);

  run_threads(nthreads, attr);
}


int main(int argc, const char *argv[]) {
  if (argc != 2) { fprintf(stderr, "Usage: ./thread_sch n_threads\n\n");  exit(1); }
  int n_threads;
  if ((n_threads = atoi(argv[1])) <= 0) {  fprintf("invalid n_threads\n\n");  exit(2);  }

  setFIFO_run_threads(n_threads);
  return  0;
}
