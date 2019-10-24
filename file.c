#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"
#include "struct.h"

int make_proj_file(char *cwd, char *fname, Proj_files_t p) {
  FILE *fp;
  char *data = NULL,
       *proj_path = NULL,
       *tmp = NULL;

  if (NULL == (proj_path = malloc(strlen(cwd) * sizeof(char) + LEN))) {
    perror("malloc() error");
    exit(EXIT_FAILURE);
  }
  if (NULL == (tmp = malloc(LEN * sizeof(char) + LEN))) {
    perror("malloc() error");
    exit(EXIT_FAILURE);
  }

  strcpy(proj_path, cwd);

  printf("%s %s\n", __FUNCTION__, cwd);

  if (strcmp(fname, p.main_c) == 0) {
    if (NULL == (data = malloc(strlen(MAIN_C_DATA) * sizeof(char) + LEN))) {
      perror("malloc() error");
      exit(EXIT_FAILURE);
    }
    snprintf(data, LEN, MAIN_C_DATA, p.proj_h);
  }
  if (strcmp(fname, p.proj_c) == 0) {
    if (NULL == (data = malloc(strlen(PROJ_C_DATA) * sizeof(char) + LEN))) {
      perror("malloc() error");
      exit(EXIT_FAILURE);
    }
    snprintf(data, LEN, "%s", PROJ_C_DATA);
  }
  if (strcmp(fname, p.proj_h) == 0) {
    if (NULL == (data = malloc(strlen(PROJ_H_DATA) * sizeof(char) + LEN))) {
      perror("malloc() error");
      exit(EXIT_FAILURE);
    }
    snprintf(tmp, LEN, PROJ_H_MACRO, p.proj_name);
    snprintf(data, LEN, PROJ_H_DATA, tmp, tmp);
  }
  if (strcmp(fname, p.readme) == 0) {
    if (NULL == (data = malloc(strlen(README_DATA) * sizeof(char) + LEN))) {
      perror("malloc() error");
      exit(EXIT_FAILURE);
    }
    snprintf(data, LEN, README_DATA, p.proj_name);
  }
  if (strcmp(fname, MAKEFILE_AM_FILE) == 0) {
    if (NULL == (data = malloc(strlen(MAKEFILE_AM_FILE) * sizeof(char) + LEN))) {
      perror("malloc() error");
      exit(EXIT_FAILURE);
    }
    snprintf(data, LEN, MAKEFILE_AM_DATA, p.proj_name, p.proj_name, p.main_c, p.proj_c);
  }
  if (strcmp(fname, CONFIGURE_AC_FILE) == 0) {
    if (NULL == (data = malloc(strlen(CONFIGURE_AC_FILE) * sizeof(char) + LEN))) {
      perror("malloc() error");
      exit(EXIT_FAILURE);
    }
    snprintf(data, LEN, CONFIGURE_AC_DATA, p.proj_name, p.proj_email);
  }
  if (strcmp(fname, AUTOMAKE_SH_FILE) == 0) {
    if (NULL == (data = malloc(strlen(AUTOMAKE_SH_FILE) * sizeof(char) + LEN))) {
      perror("malloc() error");
      exit(EXIT_FAILURE);
    }
    snprintf(data, LEN, AUTOMAKE_SH_DATA);
  }

  strcat(proj_path, fname);
  printf("'%s' exists: ", proj_path);

  if (NULL == (fp = fopen(proj_path, "r"))) {
    printf("no\nCreating %s...\n", proj_path);
  }
  if (fp != NULL) {
    printf("yes\n");
  }
  if (NULL == (fp = fopen(proj_path, "w"))) {
      perror("fopen() error");
      exit(EXIT_FAILURE);
  }

  fprintf(fp, "%s", data);

  fclose(fp);
  free(data);
  free(tmp);
  free(proj_path);

  return 0;
}
