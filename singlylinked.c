#include <stdio.h>
#include <stdlib.h>

// Definition of node
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Create linked list
void create() {
    int n, i, val;
    struct node *newnode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &val);

        newnode->data = val;
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

// Insert at beginning
void insert_first() {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data to insert at first: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

// Insert at end
void insert_end() {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data to insert at end: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

// Insert at any position
void insert_pos() {
    int pos, i;
    struct node *newnode, *temp;

    printf("Enter position: ");
    scanf("%d", &pos);

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// Display linked list
void display() {
    struct node *temp;

    if (head == NULL) {
        printf("Linked list is empty.\n");
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
    printf("2. Insert at first\n");
    printf("3. Insert at any position\n");
    printf("4. Insert at end\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: insert_first(); break;
            case 3: insert_pos(); break;
            case 4: insert_end(); break;
            case 5: display(); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
