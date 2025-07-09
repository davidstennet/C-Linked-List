#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void LL_insertAtBegin(LinkedList* list, int data) {
    // Create the new node that will be inserted
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("insertAtBegin()");
        return;
    }
    newNode->data = data;
    newNode->nextNode = NULL;

    // If first element just put at the front if not then new node points to the head and becomes the head
    if (list->head == NULL) {
        list->head = newNode;
    }
    else {
        newNode->nextNode = list->head;
        list->head = newNode;
    }

}

void LL_insertAtIndex(LinkedList* list, int data, int index) {
    if (index == 0) {
        LL_insertAtBegin(list, data);
        return;
    }

    // Create the new node that will be inserted
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("insertAtIndex()");
        return;
    }
    newNode->data = data;
    newNode->nextNode = NULL;

    // Searches to make sure the index is valid and places the node before the index in prevNode
    Node* prevNode = list->head;
    for (int i = 1; prevNode != NULL && i < index; i++) {
        prevNode = prevNode->nextNode;
    }

    // if the prevNode is NULL then the index is out of range
    // else the node is inserted at the index
    if (prevNode == NULL) {
        fprintf(stderr, "Unable to insert at index %d: index out of range\n", index);
        free(newNode);
    }
    else {
        newNode->nextNode = prevNode->nextNode;
        prevNode->nextNode = newNode;
    }
}

void LL_insertAtEnd(LinkedList* list, int data) {
    // Creat the new node that will be inserted
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("insertAtEnd()");
        return;
    }
    newNode->data = data;
    newNode->nextNode = NULL;

    // If there are no elements in the list then just input newNode at the head
    // Else check the list until the currNode is last and then input newNode as the last
    Node* currNode = list->head;
    if (currNode == NULL) {
        list->head = newNode;
    }
    else {
        while (currNode->nextNode != NULL) 
            currNode = currNode->nextNode;
        
        currNode->nextNode = newNode;
    }

}

void LL_removeFirstNode(LinkedList* list) {
    // If the list is empty can't remove the first node
    if (list->head == NULL) {
        fprintf(stderr, "Error: can't remove first node list is empty\n");
        return;
    }

    // Removes first node in the list
    Node* removedNode = list->head;
    list->head = removedNode->nextNode;
    free(removedNode);
}

void LL_removeAtIndex(LinkedList* list, int index) {
    if (index < 0) { // Invalid index
        fprintf(stderr, "Unable to remove at index %d: invalid index\n", index);
        return;
    }
    if (list->head == NULL) {
        fprintf(stderr, "Can't remove at index %d, list is empty\n", index);
        return;
    }
    if (index == 0) { // Uses first node function
        LL_removeFirstNode(list);
        return;
    }
    

    // Finds which node is right before what needs to get removed
    Node* prevNode = list->head;
    for (int i = 1; prevNode->nextNode != NULL && i < index; i++) {
        prevNode = prevNode->nextNode;
    }

    // If the index is invalid then error
    // else removes the node at that index
    if (prevNode->nextNode == NULL) {
        fprintf(stderr, "Unable to remove at index %d: index out of bounds\n", index);
    }
    else {
        Node* removedNode = prevNode->nextNode;
        prevNode->nextNode = removedNode->nextNode;
        free(removedNode);
    }
}

void LL_removeLastNode(LinkedList* list) {
    // If the list is empty can't remove the last node
    if (list->head == NULL) {
        fprintf(stderr, "Error: can't remove last node, list is empty\n");
        return;
    }

    // If the last node is the first node
    if (list->head->nextNode == NULL) {
        LL_removeFirstNode(list);
        return;
    }

    // Finds the last node in the list and removes it
    Node* prevNode = list->head;
    while (prevNode->nextNode->nextNode != NULL) 
        prevNode = prevNode->nextNode;
    free(prevNode->nextNode);
    prevNode->nextNode = NULL;
}

int LL_size(LinkedList* list) {
    Node* currNode = list->head;
    int size = 0;

    while (currNode != NULL) {
        size++;
        currNode = currNode->nextNode;
    }

    return size;
}

void LL_print(LinkedList* list) {
    // Gets node and prints error if empty
    Node* currNode = list->head;
    if (currNode == NULL) {
        fprintf(stderr, "Can't print list is empty\n");
        return;
    }

    // Prints out the index and values for the linked list
    for (int i = 0; currNode != NULL; i++) {
        printf("Index: %d, Value: %d\n", i, currNode->data);
        currNode = currNode->nextNode;
    }
}

void LL_deallocate(LinkedList* list) {
    // Iterates through the list and deallocates all of the nodes 
    Node* prevNode = NULL;
    Node* currNode = list->head;
    while (currNode != NULL) {
        prevNode = currNode;
        currNode = currNode->nextNode;
        free(prevNode);
    }
    list->head = NULL;
}