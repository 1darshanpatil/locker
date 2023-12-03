#include "showfiles.h"
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

void show_files() {
    const char *homeDir = getenv("HOME");
    char safeDir[256];
    snprintf(safeDir, sizeof(safeDir), "%s/.safe", homeDir);

    DIR *d;
    struct dirent *dir;
    d = opendir(safeDir);
    if (d) {
        printf("Files in the directory %s:\n", safeDir);
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_type == DT_REG) {  // Check if it's a regular file
                printf("%s\n", dir->d_name);
            }
        }
        closedir(d);
    } else {
        printf("Cannot open the directory %s.\n", safeDir);
    }
}

