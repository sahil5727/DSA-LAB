Double linked list

#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

// Function to insert at end
void insertEndD(struct DNode** head, int data) {
    struct DNode* newNode = (struct DNode*) malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct DNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete node by value
void deleteNodeD(struct DNode** head, int key) {
    struct DNode* temp = *head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Function to display forward
void displayForward(struct DNode* head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to display backward
void displayBackward(struct DNode* head) {
    if (head == NULL) return;

    // Go to last node
    while (head->next != NULL)
        head = head->next;

    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->prev;
    }
    printf("NULL\n");
}

// Main function to test the doubly linked list
int main() {
    struct DNode* head = NULL;

    // Insert elements
    insertEndD(&head, 5);
    insertEndD(&head, 15);
    insertEndD(&head, 25);
    insertEndD(&head, 35);

    printf("Doubly Linked List (Forward):\n");
    displayForward(head);

    printf("Doubly Linked List (Backward):\n");
    displayBackward(head);

    // Delete a middle node
    deleteNodeD(&head, 15);
    printf("After deleting 15 (Forward):\n");
    displayForward(head);

    // Delete head node
    deleteNodeD(&head, 5);
    printf("After deleting 5 (Forward):\n");
    displayForward(head);

    // Delete tail node
    deleteNodeD(&head, 35);
    printf("After deleting 35 (Forward):\n");
    displayForward(head);

    // Try to delete a node not in the list
    deleteNodeD(&head, 100);
    printf("After trying to delete 100 (not in list):\n");
    displayForward(head);

    return 0;
}
