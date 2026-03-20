#pragma comment(lib, "advapi32.lib")
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <lmcons.h>

void getuser() {
  TCHAR username[UNLEN + 1];
  DWORD username_len = UNLEN + 1;

  if (GetUserName(username, &username_len)) {
   
   printf(" %s\n", (char*)username);
  } else {
    fprintf(stderr, "Failed to get username.\n");
  }
}


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
        } else if (strcmp(argv[i], "-hi") == 0 || strcmp(argv[i], "--hello") == 0) {
         printf("Hello Word by");
         getuser();
         printf("\n");
        } else if (argv[i][0] == '-') { // Removed the extra ']' here
            printf("Unknown option: %s\n", argv[i]);
            return 1;
        } else {
          printf("Processing file: %s\n", argv[i]);  
        }
    }
    return 0;
}