#include "factorii/options.h"

fii_options *fii_options_create(char *db) {
    fii_options *opts = malloc(sizeof(fii_options));

    if (db == NULL) {
        int db_buf_size = sizeof(char *) * 1024;
        db = calloc(db_buf_size, sizeof(char *));

        snprintf(db, db_buf_size, "%s/.fii.db", util_home_dir());
    }

    opts->db_path = db;
    return opts;
}
