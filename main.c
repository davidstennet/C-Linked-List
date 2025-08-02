#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void print_separator(const char* msg) {
    printf("\n==== %s ====\n", msg);
}

int main(void) {
    LinkedList* list = LL_new();
    if (list == NULL) {
        perror("Allocation Error");
        exit(EXIT_FAILURE);
    }

    print_separator("Insert at Begin (3, 17, 2)");
    LL_insertAtBegin(list, 3);
    LL_insertAtBegin(list, 17);
    LL_insertAtBegin(list, 2);
    LL_print(list);

    print_separator("Insert at End (45)");
    LL_insertAtEnd(list, 45);
    LL_print(list);

    print_separator("Insert at Index (70 at 2)");
    LL_insertAtIndex(list, 70, 2);
    LL_print(list);

    print_separator("Insert at Invalid Index (99 at 100)");
    LL_insertAtIndex(list, 99, 100); // Should print error

    print_separator("Remove First Node");
    LL_removeFirstNode(list);
    LL_print(list);

    print_separator("Remove Last Node");
    LL_removeLastNode(list);
    LL_print(list);

    print_separator("Remove at Index (1)");
    LL_removeAtIndex(list, 1);
    LL_print(list);

    print_separator("Remove at Invalid Index (-1)");
    LL_removeAtIndex(list, -1); // Should print error

    print_separator("Remove at Invalid Index (100)");
    LL_removeAtIndex(list, 100); // Should print error

    print_separator("Size of List");
    printf("Size: %d\n", LL_size(list));

    print_separator("Deallocate List");
    LL_deallocate(list);
    LL_print(list); // Should print error

    print_separator("Remove from Empty List");
    LL_removeFirstNode(list); // Should print error
    LL_removeLastNode(list);  // Should print error
    LL_removeAtIndex(list, 0);// Should print error

    print_separator("Insert After Deallocate");
    LL_insertAtBegin(list, 42);
    LL_print(list);
    LL_deallocate(list);

    return 0;
}