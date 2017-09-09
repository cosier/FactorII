#include <getopt.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include <factorii/core.h>
#include "version.h"

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


int main(int argc, char** argv) {
    int opt = 0;
    int version = 0, help = 0;

    // Specifying the expected options
    // The two options l and b expect numbers as argument
    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'},
    };

    int long_index = 0;
    while ((opt = getopt_long(argc, argv, "hv", long_options,
                              &long_index)) != -1) {

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

    print_usage();
    return 0;
}
