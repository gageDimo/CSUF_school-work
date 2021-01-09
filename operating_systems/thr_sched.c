// Gage Dimapindan, CPSC 351-01, Fall 2020
// Thread Scheduling

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *runner (void *param) {

  int n = *(int*)param; // dereference passed in void* param
  int sum = 0;
  for (int i = 0; i <= n; ++i) {
    sum += i;
  }

  *(int*)param = sum;   // store answer in passed void* param
  pthread_exit(0);

}

void run_threads(int nthreads, pthread_attr_t attr) {

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

void test_scope(int nthreads) {

  int scope;
  pthread_attr_t attr;

  pthread_attr_init(&attr);   // get default attributes

  // first inquire on current scope
  if(pthread_attr_getscope(&attr, &scope) != 0) {
    fprintf(stderr, "Error: can't get scheduling scope\n");
  }
  else {
    printf("---------------------\n... in %s()...\n", __FUNCTION__);
    printf("---------------------\n");

    if (scope == PTHREAD_SCOPE_PROCESS) {
      printf("PTHREAD SCOPE PROCESS");
    }
    else if (scope == PTHREAD_SCOPE_SYSTEM) {
      printf("PTHREAD SCOPE SYSTEM");
    }
    else {
      fprintf(stderr, "Error: illegal scope value.\n");
    }
    printf("\n-------------------\n");
  }
  run_threads(nthreads, attr);
}

void test_policy(int nthreads) {

  int policy;
  pthread_attr_t attr;

  pthread_attr_init(&attr);     // get the default attributes

  // first inquire on the current policy
  if (pthread_attr_getschedpolicy(&attr, &policy) != 0) {
    fprintf(stderr, "Error: can't get policy");
  }
  else {
    printf("\n--------------------\n... in %s()...\n", __FUNCTION__);
    printf("\n--------------------\n");

    if (policy == SCHED_OTHER) {
      printf("SCHED OTHER");
    }
    else if (policy == SCHED_RR) {
      printf("SCHED RR");
    }
    else if (policy == SCHED_FIFO) {
      printf("SCHED FIFO");
    }
  }

  // set scheduling algorithm to PCS or SCS
  if (pthread_attr_setschedpolicy(&attr, SCHED_FIFO) != 0) {
    fprintf(stderr, "Error: can't set policy");
  }
  run_threads(nthreads, attr);
}

#define ARGC_ERROR 1
#define INVALID_NTHREADS_ERROR 2

int main(int argc, const char *argv[]) {

  printf("\n");

  if (argc != 2) {
    fprintf(stderr, "Usage: ./thr_sched nthreads\n\n");
    exit(ARGC_ERROR);
  }
  int i = atoi(argv[1]);
  if (i <= 0) {
    fprintf(stderr, "Error: invalid threads arg in command line\n\n");
    exit(INVALID_NTHREADS_ERROR);
  }

  test_scope(i);
  test_policy(2*i);

  return 0;

}
