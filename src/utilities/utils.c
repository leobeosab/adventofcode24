#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
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

void printList(DoublyLinkedList* list) {
    Node* curr = list->head;
    if ( curr == NULL ) {
        printf("empty list \n");
        return;
    }


    printf("List: ");

    while ( curr != NULL ) {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}

DoublyLinkedList* createList(int* data, int dataCount) {
    DoublyLinkedList* list = (DoublyLinkedList*) malloc(sizeof(DoublyLinkedList));

    if ( dataCount < 1 ) {
        printf("Empty count \n");
        return NULL;
    }

    Node* last;
    for ( int i = 0; i < dataCount; i++ ) {
        Node *node = (Node*) malloc(sizeof(Node)); 
        node->data = data[i];
        if ( last == NULL ) {
            list->head = node;
        }
        if ( i + 1 == dataCount ) {
            list->end = node;
        }
        if ( last != NULL ) {
            last->next = node;
            node->prev = last;
        }

        last = node;
    }

    list->count = dataCount;

    return list;
}

Node* appendNode(DoublyLinkedList* list, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    
    Node* end = list->end;
    if ( end == NULL ) {
        list->head = node;
        list->end = node;
        return node;
    }

    node->prev = end;
    end->next = node;
    list->end = node;
    list->count++;

    return node;
}

Node* prependNode(DoublyLinkedList* list, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    
    Node* head = list->head;
    if ( head == NULL ) {
        list->head = node;
        list->end = node;
        return node;
    }

    node->next = head;
    head->prev = node;
    list->head = node;
    list->count++;

    return node;
}

Node* insertAtPosition(DoublyLinkedList* list, int pos, int data) {
    if ( pos == 0 ) {
        return prependNode(list, data);
    }

    if ( pos == list->count ) {
        return appendNode(list, data);
    }

    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;

    Node* curr = list->head;
    for ( int i = 0; i < pos; i++ ) {
        if ( curr == NULL) {
            printf("Incomplete list can't continue\n");
            return NULL;
        }
        curr = curr->next;
    }


    Node* prev = curr->prev;
    prev->next = node;
    node->prev = prev;
    curr->prev = node;
    node->next = curr;

    list->count++;
    return node;
}





