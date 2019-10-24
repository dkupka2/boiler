#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include "defs.h"
#include "file.h"
#include "mem.h"
#include "struct.h"
#include "strings.h"

int make_boiler(Proj_files_t p) {
  /*
   * make dir if nodir,
   * create main.c and s.c, s.h files
   * insert preprocessor directive
   * inclusion protection in .h files
   */
  char *working_dir = getcwd(NULL, 0);
  struct stat st = {0};

  printf("check if dir '%s' exists...", p.proj_name);

  if (stat(p.proj_name, &st) == -1) {
    printf("no\nCreating dir '%s'...\n", p.proj_name);
    mkdir(p.proj_name, 0755);
  } else if (stat(p.proj_name, &st) != -1) {
    printf("yes\n");
  }

  make_work_dir_str(working_dir, p.proj_name);
  printf("working_dir string: %s\n", working_dir);
 
  p.main_c = malloc_p(p.main_c);
  p.proj_c = malloc_p(p.proj_c);
  p.proj_h = malloc_p(p.proj_h);
  p.readme = malloc_p(p.readme);

  snprintf(p.main_c, LEN, MAIN_C_FILE);
  snprintf(p.proj_c, LEN, PROJ_C_FILE, p.proj_name);
  snprintf(p.proj_h, LEN, PROJ_H_FILE, p.proj_name);
  snprintf(p.readme, LEN, README_FILE);

  printf("%s %lu\n", p.main_c, strlen(p.main_c));
  printf("%s %lu\n", p.proj_c, strlen(p.proj_c));
  printf("%s %lu\n", p.proj_h, strlen(p.proj_h));
  printf("%s %lu\n", p.readme, strlen(p.readme));

  make_proj_file(working_dir, p.main_c, p);
  make_proj_file(working_dir, p.proj_c, p);
  make_proj_file(working_dir, p.proj_h, p);
  make_proj_file(working_dir, p.readme, p);
  make_proj_file(working_dir, MAKEFILE_AM_FILE, p);
  make_proj_file(working_dir, CONFIGURE_AC_FILE, p);
  make_proj_file(working_dir, AUTOMAKE_SH_FILE, p);

  free(p.main_c);
  free(p.proj_c);
  free(p.proj_h);
  free(p.readme);

  return 0;
}
