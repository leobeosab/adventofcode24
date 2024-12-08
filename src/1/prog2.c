#include <stdio.h>
#include <stdlib.h>
#include "../utilities/utils.h"

typedef struct {
    int num;
    int multi;
} simularity;

// Use 2 increasing counters on the sorted lists to add up the number of times a number in the left list
// appears in the right list
int calculateSimilarity(simularity *listOne, int *listTwo, size_t len) {
    int left_counter = 0;
    int right_counter = 0;

    for (;;) {
        int numOne = listOne[left_counter].num;
        int numTwo = listTwo[right_counter];

        if (numOne == numTwo) {
            listOne[left_counter].multi++;
            // Break if we run out of comparisons
            if ( right_counter == len ) {
                break;
            }
            right_counter++;
            continue;
        }

        if (numTwo > numOne) {
            // If numTwo is higher than numOne and we are at the last num
            // it's impossible for the future numTwos to be a match
            if (left_counter == len) {
                break;
            }

            left_counter++;

            continue;
        }

        if (numOne > numTwo) {
            // if numOne is higher than numTwo and we are at the last num
            // it's impossible for future numOnes to be a match
            if ( right_counter == len) {
                break;
            }

            right_counter++;
            continue;
        }
    }

    int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += listOne[i].num * listOne[i].multi;
    }

    return sum;
}

// Order in ascending order
int compare (const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    FILE *fp;
    
    fp = fopen("inputs/1.txt", "r");
    if (fp == NULL) {
        printf("Error opening file \n");
        return 1;
    }

    // Calculate lines in file to create appropriate buffer sizes
    int lines = linesInFile(fp);
    simularity listOne[lines];
    int listTwo[lines];

    char lineBuffer[255];
    int c = 0;
    int numOne;
    int numTwo;
    while(fgets(lineBuffer, 255, fp) != NULL) {
        sscanf(lineBuffer, "%d   %d", &numOne, &numTwo);
        listOne[c] = (simularity){ numOne, 0 };
        listTwo[c] = numTwo;
        c++;
    }

    fclose(fp);

    // sort arrays to ascending order
    qsort(listOne, lines, sizeof(listOne[0]), compare);
    qsort(listTwo, lines, sizeof(listTwo[0]), compare);

    printf("Total distance: %d\n", calculateSimilarity(listOne, listTwo, lines));
    return 0;
}
