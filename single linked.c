Single linked list

#include <stdio.h>

#include <stdlib.h>

// Node structure for singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to delete a node by value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head, *prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not found
    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Function to display the list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to test the singly linked list
int main() {
    struct Node* head = NULL;

    // Insert elements
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Linked List after insertions:\n");
    display(head);

    // Delete an element
    deleteNode(&head, 20);
    printf("Linked List after deleting 20:\n");
    display(head);

    // Delete head element
    deleteNode(&head, 10);
    printf("Linked List after deleting 10:\n");
    display(head);

    // Delete a non-existent value
    deleteNode(&head, 100);
    printf("Linked List after trying to delete 100 (not in list):\n");
    display(head);

    return 0;
}
