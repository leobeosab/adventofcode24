#include "../utilities/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef DoublyLinkedList LList;

LList* processBlink(LList* list) {
    LList* newList = createEmptyList();


    Node* curr = list->head;
    while ( curr != NULL ) {
        long value = curr->data;
        char str [100];
        sprintf(str, "%ld", value);
        int len = strlen(str);

        if ( value == 0 ) {
            appendNode(newList, 1);
        } else if ( len % 2 == 0 ) {
            int digits = len / 2;
            char numOne[digits+1];
            char numTwo[digits+1];
            for ( int i = 0; i < len; i++ ) {
                if ( i < digits ) {
                    numOne[i] = str[i];
                } else {
                    numTwo[i - digits] = str[i];
                }
            }

            numOne[digits] = '\0';
            numTwo[digits] = '\0';

            appendNode(newList, strtol(numOne, NULL, 10));
            appendNode(newList, strtol(numTwo, NULL, 10));
        } else {
            appendNode(newList, value*2024);
        }

        curr = curr->next;
    }

    freeList(list);
    return newList;
}

int main() {
    long int arr[8] = {2, 77706, 5847, 9258441, 0, 741, 883933, 12};

    LList* list = createList(arr, 8);
    printList(list);

    for ( int i = 0; i < 25; i++ ) {
        list = processBlink(list);
        printList(list);
    }

    Node* curr = list->head;
    int count = 0;

    while ( curr != NULL ) {
        count++;
        curr = curr->next;
    }

    freeList(list);

    printf("COUNT: %d\n", count);
}
