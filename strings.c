#include <stdio.h>
#include <string.h>
#include "defs.h"

char * get_string(char *str) {
  fgets(str, LEN, stdin);
  str[strlen(str) - 1] = '\0';
  return str;
}

char * make_work_dir_str(char *cwd, char *work_dir) {
  cwd[strlen(cwd)] = '/';
  strcat(cwd, work_dir);
  cwd[strlen(cwd)] = '/';
  return cwd;
}
