#ifndef STRUCT_H
#define STRUCT_H

#include "defs.h"

typedef struct proj_files {
  char *proj_name,
       *proj_email,
       *main_c,
       *proj_c,
       *proj_h,
       *readme;
} Proj_files_t;

#endif

