#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

void * malloc_p(void *m) {
  if (NULL == (m = malloc(LEN * sizeof(void *)))) {
    perror("malloc() error");
    exit(EXIT_FAILURE);
  }
  return m;
}
