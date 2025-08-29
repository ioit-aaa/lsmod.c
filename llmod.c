#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int get_mode(const char *path) {
    struct stat st;
    if (stat(path, &st) != 0) {
        perror(path);
        return -1;
    }
    return st.st_mode & 0777;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        int mode = get_mode(argv[i]);
        if (mode >= 0) {
            printf("%03o %s\n", mode, argv[i]);
        }
    }

    return 0;
}
