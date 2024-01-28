#include "viewfile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_COMMAND_LENGTH 1024

void view_file() {
    char filename[MAX_FILENAME_LENGTH];
    char decrypted_filename[MAX_FILENAME_LENGTH + 4];
    char password[50];
    char command[MAX_COMMAND_LENGTH];

    printf("Enter the filename to view (without .enc): ");
    scanf("%s", filename);

    snprintf(decrypted_filename, sizeof(decrypted_filename), "%s.dec", filename);

    printf("Enter password for decryption: ");
    scanf("%s", password);

    const char *homeDir = getenv("HOME");
    snprintf(command, sizeof(command), "openssl enc -d -aes-256-cbc -salt -pbkdf2 -in %s/.safe/%s.enc -out %s.dec -pass pass:%s", homeDir, filename, filename, password);
    system(command);

    snprintf(command, sizeof(command), "cat %s.dec", filename);
    system(command);

//    snprintf(command, sizeof(command), "rm %s.dec", filename);
    snprintf(command, sizeof(command), "shred -u %s.dec", filename);
    system(command);

    printf("File viewed and decrypted file removed.\n");
}

