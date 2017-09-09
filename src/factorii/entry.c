#include "factorii/entry.h"

fii_entry* fii_entry_create(char* name, char* code) {
    fii_entry* entry = malloc(sizeof(fii_entry));
    entry->name = name;
    entry->code = code;
    return entry;
}

void fii_entry_free(fii_entry* entry) {
    if (entry == NULL) {
        return
    };

    free(entry->name);
    free(entry->code);
    free(entry);
}
