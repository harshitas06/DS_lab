#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Function to create a linked list
struct node* create() {
    int n, i;
    struct node *head = NULL, *temp = NULL, *newnode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

// Display linked list
void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Sort linked list (Bubble sort by swapping data)
void sort(struct node *head) {
    struct node *i, *j;
    int t;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                t = i->data;
                i->data = j->data;
                j->data = t;
            }
        }
    }
}

// Reverse linked list
struct node* reverse(struct node *head) {
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Concatenate two linked lists
struct node* concatenate(struct node *head1, struct node *head2) {
    struct node *temp = head1;

    if (head1 == NULL)
        return head2;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    struct node *head1, *head2;

    printf("\nCreate first linked list\n");
    head1 = create();

    printf("\nCreate second linked list\n");
    head2 = create();

    printf("\nFirst Linked List:\n");
    display(head1);

    printf("\nSecond Linked List:\n");
    display(head2);

    printf("\nSorted First List:\n");
    sort(head1);
    display(head1);

    printf("\nReversed First List:\n");
    head1 = reverse(head1);
    display(head1);

    printf("\nConcatenated List:\n");
    head1 = concatenate(head1, head2);
    display(head1);

    return 0;
}
