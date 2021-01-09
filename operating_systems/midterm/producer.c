#include "shared_mem.h"

static char* NAME = "OS";
static off_t SIZE = 4096;

void write_msg(char** p, const char* msg) {
  sprintf(*p, "%s ", msg);
  *p += strlen(msg) + 1;
}

static void test_shared_write(int argc, const char* argv[]) {
  int fd = shm_open(NAME, O_CREAT | O_RDWR, 0666);
  ftruncate(fd, SIZE);
                                                    // TODO


}

int main(int argc, const char * argv[]) { // producer
  test_shared_write(argc, argv);
  
  return 0;
}

