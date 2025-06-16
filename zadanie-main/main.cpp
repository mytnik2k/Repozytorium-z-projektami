#include <iostream>
#include "stack.h"

void clear(void) {
    while (getchar() != '\n');
}

void menu(void) {
    printf("SIMPLE LINKED LIST using structures\n");
    printf("1. Add an element at the stack\n");
    printf("2. remove an element from the stack\n");
    printf("3. Read an element from the stack(top)\n");
    printf("4. Is the stack empty\n");
    printf("5. Print the stack inventory\n\n");
    printf("0. Exit\n\n");

}

int main()
{
    int value = 0, index = 0, option = 0, errorCode = 0;
    while (1) {
        menu();
        while (!scanf("%d", &option)) {
            printf("Not an integer! Input an integer: ");
            clear();
        }
        switch (option) {
            case 1: // add at the front

                printf("Input a number: ");
                while (!scanf("%d", &value)) {
                    printf("Not an integer! Input an integer: ");
                    clear();
                }
                errorCode = insertFront(value);
                !errorCode ? printf("Added successfully!\n\n") : printf("Failed to add.\n\n");
                break;

            case 2: // add at the back

                errorCode = deleteFront();
                !errorCode ? printf("First element deleted successfully!\n\n") : printf("Failed to delete the first element.\n\n");
                break;

            case 3: // add after a certain node

                if (!isStackempty()) {
                    int value = Top();
                    printf("Recorded element: %d\n", value);
                } else {
                    printf("Operacja niedozwolona: stos pusty!!!\n\n");
                }
                break;

            case 4: // delete the first element

                if (isStackempty()) {
                    printf("STACK is empty.\n");
                }
                else {
                    printf("STACK is not empty.\n");
                }
                break;

            case 5: // delete the first element
                printf("Stack: ");
                printList();
                printf("\n%d elements\n\n", getNodesCount());
                break;

            case 0:
                freeList();
                return 0;

            default:

                printf("Wybierz wlasciwa opcje.\n\n");
                break;
        }
    }
    freeList();
    return 0;
}