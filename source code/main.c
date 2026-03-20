#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No arguments provided. Use -h for help.\n"); // Added semicolon here
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            printf("Usage: main.exe [options]\n");
            printf("Options:\n");
            printf("  -h, --help     Show this help message\n");
            printf("  -v, --version  Show version info\n");
            return 0;
        } else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0) {
            printf("Version 1.0\n");
            return 0;
        } else if (argv[i][0] == '-') { // Removed the extra ']' here
            printf("Unknown option: %s\n", argv[i]);
            return 1;
        } else {
            printf("Processing file: %s\n", argv[i]);  
        }
    }
    return 0;
}
