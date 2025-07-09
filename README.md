# C-Linked-List

linkedlist.c and linkedlist.h are the implementation and header files for a Linked List ADT
In main.c there are a number of test cases that are used to show what exactly each function does and that they work

Here is a list of the functions associated with this ADT:
------------------------------------------------------------
void LL_insertAtBegin(LinkedList* list, int data)
void LL_insertAtIndex(LinkedList* list, int data, int index)
void LL_insertAtEnd(LinkedList* list, int data)
void LL_removeFirstNode(LinkedList* list)
void LL_removeAtIndex(LinkedList* list, int index)
void LL_removeLastNode(LinkedList* list)
int LL_size(LinkedList* list)
void LL_print(LinkedList* list)
void LL_deallocate(LinkedList* list)
------------------------------------------------------------

In order to run this file you can recompile the files as you see fit or if you are using the gcc compiler you can just run
./linkedlist and it will run the tests for main