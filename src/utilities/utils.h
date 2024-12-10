#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

int linesInFile(FILE *fp);
void printArr(int* arr, size_t size);
void printArrInGrid(int* arr, size_t size, int rowSize);

#endif
