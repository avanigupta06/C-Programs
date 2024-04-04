#include <stdio.h>
#include <stdlib.h>

int top = -1;
// declare function
void Push(int stack[], int size, int *top, int item);
void Pop(int stack[], int *top);
void Traverse(int stack[], int top);

int main() {
    int size;
    printf("Enter size of stack: ");
    scanf("%d", &size);
    int stack[size];
    int item;
    int choice;
    // printf("enter your choice :");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &item);
                Push(stack, size, &top, item);
                break;

            case 2:
                Pop(stack, &top);
                break;

            case 3:
                Traverse(stack, top);
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
// defination of function

// Function of push
void Push(int stack[], int size, int *top, int item) {
    if (*top == size - 1) {
        printf("Overflow\n");
        return;
    } else {
        (*top)++;
        stack[*top] = item;
    }
}

// Function of pop
void Pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Underflow\n");
        return;
    } else {
        int temp = stack[*top];
        (*top)--;
        printf("Popped item: %d\n", temp);
    }
}

// Function to traverse
void Traverse(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements:\n");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

