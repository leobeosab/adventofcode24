#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

int linesInFile(FILE *fp);
int intNotInArr(int* arr, size_t size, int target);
void printArr(int* arr, size_t size);
void printArrInGrid(int* arr, size_t size, int rowSize);

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct DoublyLinkedList {
    int count;
    struct Node* head;
    struct Node* end;
} DoublyLinkedList;

DoublyLinkedList* createList(int* data, int dataCount);
Node* appendNode(DoublyLinkedList* list, int data);
Node* prependNode(DoublyLinkedList* list, int data);
Node* insertAtPosition(DoublyLinkedList* list, int pos, int data);
// TODO add delete funcs
Node* deleteHead(DoublyLinkedList*);
Node* deleteEnd(DoublyLinkedList*);
Node* deleteAtPosition(DoublyLinkedList*);
void printList(DoublyLinkedList* list);

#endif
