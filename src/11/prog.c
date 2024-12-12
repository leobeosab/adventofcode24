#include "../utilities/utils.h"
#include <stdio.h>
#include <stdlib.h>

typedef DoublyLinkedList list;

int main() {
    int arr[5] = { 1, 2, 3, 4, 5 };

    list* list = createList(arr, sizeof(arr) / sizeof(*arr));
    printList(list);

    prependNode(list, 10);
    printList(list);

    appendNode(list, 11);
    printList(list);

    insertAtPosition(list, 7, 69);
    printList(list);
}
