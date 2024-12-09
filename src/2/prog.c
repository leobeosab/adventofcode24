#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../utilities/utils.h"

int processReport(char *input);

int main() {
    FILE *fp;
    
    fp = fopen("inputs/2.txt", "r");
    if (fp == NULL) {
        printf("Error opening file \n");
        return 1;
    }

    // Calculate lines in file to create appropriate buffer sizes
    int lines = linesInFile(fp);
    int listOne[lines];
    int listTwo[lines];

    char lineBuffer[255];
    int c = 0;
    int validReports = 0;

    while(fgets(lineBuffer, 255, fp) != NULL) {
        validReports += processReport(lineBuffer);
        c++;
    }

    fclose(fp);

    printf("Valid Reports count: %d \n", validReports);

    return 0;
}

int processReport(char *input) {
    int size = 10;
    int* numbers = (int*)malloc(size * sizeof(int));
    int count = 0;

    printf("Current line: %s", input);

    char* token = strtok(input, " ");
    while (token != NULL) {
        // increase array size if need be
        if (count == size) {
            size *= 2;
            int *temp = realloc(numbers, size * sizeof *numbers);
            assert (temp != NULL);
        }

        int num = atoi(token);
        numbers[count] = num;
        count++;

        token = strtok(NULL, " ");
    }

    
    int result = 0;
    int prvLvlDiff = 0;
    for (int i = 0; i < count; i++) {
        if ( i + 1 == count ) {
            result = 1;
            break;
        }

        int lvlDiff = numbers[i] - numbers[i + 1];

        if ( abs(lvlDiff) > 3 || abs(lvlDiff) < 1 ) {
            break;
        }

        if ( prvLvlDiff > 0 && lvlDiff < 0 || prvLvlDiff < 0 && lvlDiff > 0) {
            break;
        }

        prvLvlDiff = lvlDiff;

    }

    free(numbers);
    printf(" \n");
    return result;
}
