//
// Created by student on 26.05.2025.
//

#ifndef STOS2_STACK_H
#define STOS2_STACK_H

int insertFront(int element);
// Inserts passed argument at the front of the list
// Returns:
// EXIT_SUCCESS (0), if added successfully
// EXIT_FAILURE (1), if couldn't add (memory allocation fail)



/* ---------- DELETING ---------- */

int deleteFront();
// Deletes the first element from the list
// Returns:
// EXIT_SUCCESS (0), if deleted successfully
// EXIT_FAILURE (1), if couldn't delete (no nodes)


/* ---------- OTHER ---------- */

int searchList(int key);
// Checks whether given element is present in the list
// Returns:
// EXIT_SUCCESS (0), if the element is present
// EXIT_FAILURE (1), if the element is not present

void printList(void);
// Prints the list

int isStackempty(void);

int Top();



int getNodesCount();
// Returns the current amount of elements (nodes)

void freeList(void);
// Frees memory allocated by the list

#endif //STOS2_STACK_H
