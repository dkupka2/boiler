#ifndef DEF_H
#define DEF_H

#define CONFIGURE_AC_DATA "AC_INIT([%s],[0.1],[%s])\nAM_INIT_AUTOMAKE\nAC_PROG_CC\nAC_CONFIG_FILES([Makefile])\nAC_OUTPUT"
#define CONFIGURE_AC_FILE "configure.ac"
#define AUTOMAKE_SH_DATA "#!/bin/sh\naclocal &&\nautoconf &&\nautomake --add-missing &&\n./configure &&\nmake\n# make dist &&\n# make distcheck &&\n# make install &&\nls"
#define AUTOMAKE_SH_FILE "automake.sh"
#define LEN 256
#define MAIN_C_FILE "main.c"
#define MAIN_C_DATA "#include <stdio.h>\n#include \"%s\"\n\nint main(int argc, char **argv) {\n\tprintf(\"test!\\n\");\n\treturn 0;\n}"
#define MAKEFILE_AM_DATA "AUTOMAKE_OPTIONS = foreign\nbin_PROGRAMS = %s\n%s_SOURCES = %s %s"
#define MAKEFILE_AM_FILE "Makefile.am"
#define PROJ_C_FILE "%s.c"
#define PROJ_H_FILE "%s.h"
#define PROJ_H_MACRO "%s_H"
#define PROJ_C_DATA "// insert preprocessor directives and functions here"
#define PROJ_H_DATA "#ifndef %s\n#define %s\n// insert preprocessor directives here\n\n#endif"
#define README_FILE "README.md"
#define README_MACRO "README_H"
#define README_DATA "This is the README file for project '%s'"
#endif
