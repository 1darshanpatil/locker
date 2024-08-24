#include "adduser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_COMMAND_LENGTH 1024

/**
 * Checks if a file exists on the filesystem.
 * 
 * @param filename The name of the file to check.
 * @return Returns 1 if the file exists, 0 otherwise.
 */
int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

/**
 * Encrypts a file with AES-256-CBC encryption using OpenSSL and removes the original file.
 * 
 * @param filename The name of the file to encrypt.
 * @param password The password used for encryption.
 */
void encrypt_file(const char *filename, const char *password) {
    char encrypted_filename[MAX_FILENAME_LENGTH + 100];
    const char *homeDir = getenv("HOME");
    snprintf(encrypted_filename, sizeof(encrypted_filename), "%s/.safe/%s.enc", homeDir, filename);

    char command[MAX_COMMAND_LENGTH];
    snprintf(command, sizeof(command), "openssl enc -aes-256-cbc -salt -pbkdf2 -in %s -out %s -pass pass:%s", filename, encrypted_filename, password);
    system(command);

    snprintf(command, sizeof(command), "rm %s", filename);
    system(command);

    printf("File encrypted and original file removed: %s\n", encrypted_filename);
}

/**
 * Interacts with the user to specify a file for encryption and a password,
 * and handles the encryption process.
 */
void add_user() {
    char filename[MAX_FILENAME_LENGTH];
    char password[50];

    printf("Enter the filename: ");
    scanf("%s", filename);

    const char *homeDir = getenv("HOME");
    char encrypted_filename[MAX_FILENAME_LENGTH + 100];
    snprintf(encrypted_filename, sizeof(encrypted_filename), "%s/.safe/%s.enc", homeDir, filename);

    if (file_exists(filename) || file_exists(encrypted_filename)) {
        printf("Error: File '%s' or '%s' already exists.\n", filename, encrypted_filename);
        return;
    }

    printf("Enter password for encryption: ");
    scanf("%s", password);

    char command[MAX_FILENAME_LENGTH + 10];
    snprintf(command, sizeof(command), "nano %s", filename);
    system(command);

    encrypt_file(filename, password);
}
