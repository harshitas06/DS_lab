#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create linked list
void create() {
    int n, i;
    struct node *newnode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

// Delete first node
void delete_first() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Delete specified element
void delete_specified() {
    int key;
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter element to delete: ");
    scanf("%d", &key);

    // If first node is to be deleted
    if (head->data == key) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Element %d deleted.\n", key);
        return;
    }

    prev = head;
    temp = head->next;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Element %d deleted.\n", key);
}

// Delete last node
void delete_last() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    prev = head;
    temp = head->next;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Display linked list
void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Linked list contents:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    printf("\n--- SINGLY LINKED LIST OPERATIONS ---\n");
    printf("1. Create list\n");
    printf("2. Delete first element\n");
    printf("3. Delete specified element\n");
    printf("4. Delete last element\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: delete_first(); break;
            case 3: delete_specified(); break;
            case 4: delete_last(); break;
            case 5: display(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
