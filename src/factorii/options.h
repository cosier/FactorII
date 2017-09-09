#ifndef FII_OPTIONS_H
#define FII_OPTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <ubelt/utils.h>

typedef struct fii_options {
    char *db_path;
} fii_options;

fii_options* fii_options_create(char *db);

#endif
