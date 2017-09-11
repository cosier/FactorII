#ifndef FII_ENTRY_H
#define FII_ENTRY_H

#include <stdlib.h>

typedef struct fii_entry {
    char *name;
    char *code;
} fii_entry;

fii_entry *fii_entry_create(char *name, char *code);
void fii_entry_free(fii_entry *entry);

#endif
