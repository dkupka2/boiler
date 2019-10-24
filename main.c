#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boiler.h"
#include "defs.h"
#include "strings.h"

int main(int argc, char **argv) {
  Proj_files_t p;

  if (NULL == (p.proj_name = malloc(LEN * sizeof(char)))) {
    perror("malloc error()");
    exit(EXIT_FAILURE);    
  }
  if (NULL == (p.proj_email = malloc(LEN * sizeof(char)))) {
    perror("malloc error()");
    exit(EXIT_FAILURE);    
  }

  if (argc < 2) {
    printf("Enter project name: ");
    get_string(p.proj_name);
  } else {
    strcpy(p.proj_name, argv[1]);
  }

  printf("Enter project maintainer's email address: ");
  get_string(p.proj_email);

  make_boiler(p);

  free(p.proj_name);
  free(p.proj_email);

  exit(EXIT_SUCCESS);
}
