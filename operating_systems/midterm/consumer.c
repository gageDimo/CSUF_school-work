#include "shared_mem.h"

static void test_shared_read(void) {
  int fd = shm_open(NAME, O_RDWR, 0666);
  ftruncate(fd, SIZE);
                          // TODO

  shm_unlink(NAME);
}


static void test_shared_read(void) {
  
  int fd = shm_open(NAME, O_RDWR, 0666);   // octal
  ftruncate(fd, SIZE);
  char* p = (char*) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  printf("p is: %p\n", p);
  shared_read(p);

  shm_unlink(NAME);
}

int main(int argc, const char * argv[]) {  // producer
  test_shared_read();
  
  return 0;
}

