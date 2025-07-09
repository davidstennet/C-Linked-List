#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int data;
    struct Node* nextNode;
} Node;

typedef struct {
    Node* head;
} LinkedList;

// Inserts a node at the beginning of the linkedlist
void LL_insertAtBegin(LinkedList* list, int data);

// Inserts a node of a linkedlist at a specified index
void LL_insertAtIndex(LinkedList* list, int data, int index);

// Inserts a node at the end of the linkedlist
void LL_insertAtEnd(LinkedList* list, int data);

// Removes the first index in the list
void LL_removeFirstNode(LinkedList* list);

// Removes a node at the specified index
void LL_removeAtIndex(LinkedList* list, int index);

// Removes the last node in the list
void LL_removeLastNode(LinkedList* list);

// Returns the size of inputed linkedlist
int LL_size(LinkedList* list);

// Prints out the list with their corresponding index and value
void LL_print(LinkedList* list);

// Deallocates all of the nodes in the linkedlist
void LL_deallocate(LinkedList* list);

#endif