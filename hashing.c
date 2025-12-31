#include <stdio.h>

#define SIZE 10   // Size of hash table

int hashTable[SIZE];

// Initialize hash table
void initHashTable() {
    int i;
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert key using Linear Probing
void insert(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;

        if (index == startIndex) {
            printf("Hash Table is Full. Cannot insert %d\n", key);
            return;
        }
    }

    hashTable[index] = key;
}

// Display hash table
void display() {
    int i;
    printf("\nHash Table:\n");
    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Index %d : %d\n", i, hashTable[i]);
        else
            printf("Index %d : ---\n", i);
    }
}

int main() {
    int n, key, i;

    initHashTable();

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}
