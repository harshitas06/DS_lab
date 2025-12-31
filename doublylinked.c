#include <stdio.h>
#include <stdlib.h>

// Definition of doubly linked list node
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Create doubly linked list
void create() {
    int n, i;
    struct node *newnode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
}

// Insert new node to the left of a given value
void insert_left() {
    int key;
    struct node *newnode, *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to insert to the left of: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter new data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newnode;
    else
        head = newnode;

    temp->prev = newnode;

    printf("Node inserted successfully.\n");
}

// Delete node with specific value
void delete_node() {
    int key;
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Display doubly linked list
void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Doubly Linked List contents:\n");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    printf("\n--- DOUBLY LINKED LIST OPERATIONS ---\n");
    printf("1. Create list\n");
    printf("2. Insert node to left of a value\n");
    printf("3. Delete node by value\n");
    printf("4. Display list\n");
    printf("5. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: insert_left(); break;
            case 3: delete_node(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
