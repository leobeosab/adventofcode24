#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../utilities/utils.h"
#define TOLERANCE 1

int processReport(int* numbers, int count, int failures);
int formatReport(char* input, int* numbers, int size);
void removeIntFromArray(int* numbersIn, int* numbersOut, int target, int size);

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
    int size = 10;

    while(fgets(lineBuffer, 255, fp) != NULL) {
        int* numbers;
        numbers = (int*)malloc(size * sizeof(int));
        int count = formatReport(lineBuffer, numbers, size);
        validReports += processReport(numbers, count, 0);
        c++;
    }

    fclose(fp);

    printf("Valid Reports count: %d \n", validReports);

    return 0;
}

int formatReport(char *input, int* numbers, int size) {
    int count = 0;

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

    return count;
}

int processReport(int* numbers, int count, int failures) {
    if (failures == 1) {
        printf("failure run: ");
        printArr(numbers, count);
    }

    int result = 0;
    int prvLvlDiff = 0;
    int fails = 0;

    for (int i = 0; i < count; i++) {
        if ( i + 1 == count && fails == 0) {
            result = 1;
            break;
        }

        int lvlDiff = numbers[i] - numbers[i + 1];

        if ( 
            abs(lvlDiff) > 3 || abs(lvlDiff) < 1 ||
            (prvLvlDiff > 0 && lvlDiff < 0) || (prvLvlDiff < 0 && lvlDiff > 0)
        ) {
            break;
        }

        prvLvlDiff = lvlDiff;
    }

    // there is a smarter way to do this but we are just trying again without each number
    if (result == 0 && failures < TOLERANCE) {
        for ( int i = 0; i < count; i++) {
            printArr(numbers, count);
            printf("Trying without %d \n", numbers[i]);

            int* newArr = (int*)malloc( count-1 * sizeof(*numbers));
            removeIntFromArray(numbers, newArr, i, count);
            result = processReport(newArr, count-1, failures+1);
            if (result == 1) {
                break;
            }

            printf("result without %d: %d\n", numbers[i], result);
        }
    }

    free(numbers);
    return result;
}

void removeIntFromArray(int* numbersIn, int* numbersOut, int target, int size) {
    int found = 0;
    for ( int i = 0; i < size; i++ ) {
        if ( i == target ) {
            found = 1;
            continue;
        }

        numbersOut[i-found] = numbersIn[i];
    }
}
