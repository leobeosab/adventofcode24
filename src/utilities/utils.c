#include <stdio.h>
#define BUFF_SIZE 65536

int linesInFile(FILE *fp) {
    if (fp == NULL) {
        printf("File isn't open \n");
        return -1;
    }

    // make sure fp is at the start
    rewind(fp);

    char buffer[BUFF_SIZE];
    int count = 0;

    // read entire file, in chunks of BUFF_SIZE
    for (;;) {
        size_t res = fread(buffer, 1, BUFF_SIZE, fp);
        if (ferror(fp))
            return -1;
        
        // loop through buffer, checking for newlines, increment counter if found
        for (int i = 0; i < res; i++) {
            if (buffer[i] == '\n')
                count++;
        }

        if (feof(fp))
            break;

    }

    // reset file to start
    rewind(fp);

    return count;
}
