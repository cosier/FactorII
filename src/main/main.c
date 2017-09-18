#include <factorii/core.h>
#ifdef UNIX_OS
#include <getopt.h>
#endif

#ifdef WINDOWS_OS
#include <factorii/support/xgetopt.h>
#endif


void print_usage() {
    printf("Usage: factorii [options]\n\n");

    printf("\nOptions:\n");
    printf("  -h, --help     Show application usage\n");
    printf("  -v, --version  Print version\n\n");
}

void print_version() {
    printf("Factorii v%s.%s.%s\nrevision: %s\nbuild date: %s\n\n",
           APP_VERSION_MAJOR, APP_VERSION_MINOR, APP_VERSION_PATCH,
           APP_VERSION_BUILD, APP_VERSION_DATE);

    printf("Authors: Bailey Cosier <bailey@cosier.ca>\n");
    printf("Homepage: https://github.com/cosier/factorii\n\n");
}

int main(int argc, char **argv) {
    int opt = 0;
    int version = 0, help = 0;

    while ((opt = getopt(argc, argv, "hv")) != -1) {
        switch (opt) {
        case 'v':
            version = 1;
            break;

        case 'h':
            help = 1;
            break;

        default:
            print_usage();
            return 1;
        }
    }

    // Version output and then exit.
    if (version) {
        print_version();
        return 0;
    }

    // Show cli help usage and exit.
    if (help) {
        print_usage();
        return 0;
    }

    fii_options *opts = fii_options_create(NULL);
    fii_interface(opts);

    return 0;
}
