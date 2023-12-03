#include "showfiles.h"
#include "adduser.h"
#include "viewfile.h"
#include "updatefile.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *homeDir = getenv("HOME");
    char safeDir[256];
    snprintf(safeDir, sizeof(safeDir), "%s/.safe", homeDir);

    struct stat st = {0};
    if (stat(safeDir, &st) == -1) {
        mkdir(safeDir, 0700);
    }

    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "updatefile") == 0) {
        update_file();
    } else if (strcmp(argv[1], "adduser") == 0) {
        add_user();
    } else if (strcmp(argv[1], "showfiles") == 0) {
        show_files();
    } else if (strcmp(argv[1], "viewfile") == 0) {
        view_file();
    } else {
        printf("Unknown command: %s\n", argv[1]);
    }

    return 0;
}

