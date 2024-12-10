#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

int linesInFile(FILE *fp);
int intNotInArr(int* arr, size_t size, int target);
void printArr(int* arr, size_t size);
void printArrInGrid(int* arr, size_t size, int rowSize);

#endif
