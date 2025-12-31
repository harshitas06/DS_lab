#include <stdio.h>
#define MAX 3

int cq[MAX];
int front = -1, rear = -1;

// Insert operation
void insert() {
    int item;

    // Overflow condition
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);

    if (front == -1) {           // First insertion
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    cq[rear] = item;
    printf("Inserted element: %d\n", item);
}

// Delete operation
void delete() {
    if (front == -1) {
        printf("Queue Empty! Cannot delete.\n");
        return;
    }

    printf("Deleted element: %d\n", cq[front]);

    if (front == rear) {         // Last element deleted
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Display operation
void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements:\n");

    if (front <= rear) {
        for (i = front; i <= rear; i++)
            printf("%d ", cq[i]);
    } else {
        for (i = front; i < MAX; i++)
            printf("%d ", cq[i]);
        for (i = 0; i <= rear; i++)
            printf("%d ", cq[i]);
    }

    printf("\n");
}

int main() {
    int choice;

    // Menu printed only once
    printf("\n--- CIRCULAR QUEUE OPERATIONS ---\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
