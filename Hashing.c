#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
typedef struct node {
    int data;
    struct node *next;
} Node;
Node *hashTable[SIZE] = {NULL};

void insert(int key) {
    int index = key % SIZE;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}
void display() {
    for (int i = 0; i < SIZE; i++) {
        Node *temp = hashTable[i];
        printf("Index %d: ", i);
        while (temp != NULL) { printf("%d ", temp->data); temp = temp->next; }
        printf("\n");
    }
}
int main() {
    insert(10); insert(20); insert(12); insert(22); display();
    return 0;
}
