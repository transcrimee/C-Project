#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "ws2_32.lib")
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <lmcons.h>
#include <winsock.h>
#include <sys/stat.h>

void network() {
 WSADATA wsaData;
 char hostname[256];
 struct hostent *host_entry;
 int i = 0;
 // Initialize Winsock
 if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) return 1;
 gethostname(hostname, sizeof(hostname));
 printf("Host: %s\n", hostname);

 host_entry = gethostbyname(hostname);
 
// Get the hostname and print the IP addresses associated with the hostname
 while (host_entry->h_addr_list[i] != NULL) {
    printf("IP: %s\n", inet_ntoa(*(struct in_addr *)host_entry->h_addr_list[i]));
    i++;
 }
  WSACleanup();
  return 0;

}

void getuser() {
  TCHAR username[UNLEN + 1];
  DWORD username_len = UNLEN + 1;
  // Get the username of the current user
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
     // Process command-line arguments
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
         printf("---------------\n");
         network();
        } else if (strcmp(argv[i], "-dir") == 0) {
            // Check if the next argument is -mk and if there is a directory name provided
            if (i + 2 < argc && strcmp(argv[i+1], "-mk") == 0) {
                const char *dirName = argv[i+2];
                #ifdef _WIN32
                    int result = _mkdir(dirName);
                #else
                    int result = mkdir(dirName, 0777);
                #endif
                // Check if the directory was created successfully
                if (result == 0) printf("Directory '%s' created.\n", dirName);
                else perror("Error creating directory");

                i = 2;
                continue;
            } else {
              printf("Error: -dir requires -mk <name>\n");
              return 1; 
            }
        } else if (argv[i][0] == '-') { // Removed the extra ']' here
            printf("Unknown option: %s\n", argv[i]);
            return 1;
        } else {
          printf("Processing file: %s\n", argv[i]);  
        }
    }
    return 0;
}