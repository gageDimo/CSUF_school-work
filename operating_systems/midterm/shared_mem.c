#include "shared_mem.h"

const int SIZE = 4096;
const char* NAME = "OS";

void shared_write(char* pmem, const char* msg, size_t* sizeleft) {
  size_t len = strlen(msg);
  size_t n_written = *sizeleft < len ? *sizeleft : len;
  snprintf(pmem, n_written, "%s", msg);
  pmem += n_written;
  *sizeleft -= n_written;
}

void shared_read(char* pmem) { printf("%s", pmem); }

