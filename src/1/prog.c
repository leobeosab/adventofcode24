#include <stdio.h>
#include <stdlib.h>
#include "../utilities/utils.h"


int calculateDistance(int *listOne, int *listTwo, size_t len) {
    
    int counter = 0;

    for (int i = 0; i < len; i++) {
        counter += abs(listOne[i] - listTwo[i]);
    }

    return counter;
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
    int listOne[lines];
    int listTwo[lines];

    char lineBuffer[255];
    int c = 0;
    int numOne;
    int numTwo;
    while(fgets(lineBuffer, 255, fp) != NULL) {
        sscanf(lineBuffer, "%d   %d", &numOne, &numTwo);
        listOne[c] = numOne;
        listTwo[c] = numTwo;
        c++;
    }

    fclose(fp);

    // sort arrays to ascending order
    qsort(listOne, lines, sizeof(listOne[0]), compare);
    qsort(listTwo, lines, sizeof(listTwo[0]), compare);

    printf("Total distance: %d\n", calculateDistance(listOne, listTwo, lines));
    return 0;
}
