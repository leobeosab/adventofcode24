#include "utils.h"
#include <stdio.h>
#include <assert.h>
#define BUFF_SIZE 65536

int linesInFile(FILE *fp) {
    assert(fp != NULL);

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

void printArr(int* arr, size_t size) {
    for ( int i = 0; i < size; i++ ) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void printArrInGrid(int* arr, size_t size, int rowSize) {
    for ( int i = 0; i < size; i++ ) {
        if ( i % rowSize == 0 ) {
            printf("\n");
        }
        printf("%d", arr[i]);
    }
    printf("\n");
}

int intNotInArr(int* arr, size_t size, int target) {
    for ( int i = 0; i < size; i++) {
        if ( arr[i] == target ) {
            return 0;
        }
    }

    return 1;
}

