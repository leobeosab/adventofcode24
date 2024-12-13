#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

int linesInFile(FILE *fp);
int intNotInArr(int* arr, size_t size, int target);
void printArr(int* arr, size_t size);
void printArrInGrid(int* arr, size_t size, int rowSize);

typedef struct Node {
    long data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct DoublyLinkedList {
    int count;
    struct Node* head;
    struct Node* end;
} DoublyLinkedList;

DoublyLinkedList* createList(long* data, int dataCount);
DoublyLinkedList* createEmptyList();
Node* appendNode(DoublyLinkedList* list, long data);
Node* prependNode(DoublyLinkedList* list, long data);
Node* insertAtPosition(DoublyLinkedList* list, int pos, long data);
void freeList(DoublyLinkedList* list);
// TODO add delete funcs
Node* deleteHead(DoublyLinkedList*);
Node* deleteEnd(DoublyLinkedList*);
Node* deleteAtPosition(DoublyLinkedList*);
void printList(DoublyLinkedList* list);

#endif
