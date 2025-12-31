#include <stdio.h>
#define MAX 5   // Maximum size of stack

int stack[MAX];
int top = -1;

// Function to push an element
void push() {
    int item;
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push element.\n");
        return;
    }
    printf("Enter element to push: ");
    scanf("%d", &item);
    top++;
    stack[top] = item;
    printf("Element %d pushed successfully.\n", item);
}

// Function to pop an element
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop element.\n");
        return;
    }
    printf("Popped element: %d\n", stack[top]);
    top--;
}

// Function to display stack elements
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice;

    do {
        printf("\n--- STACK OPERATIONS ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
