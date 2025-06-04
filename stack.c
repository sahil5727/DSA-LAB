// Stack operations in C
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

// Stack Implementation 
// Stack array and top pointer
int stack[SIZE];
int top = -1;

// Function to push an element to the stack
void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d popped from stack\n", stack[top--]);
}

// Function to view the top element of the stack
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", stack[top]);
}

// Function to display all elements in the stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

//  Linear Queue Implementation 
// Linear queue array and front-rear pointers
int lqueue[SIZE];
int front = -1, rear = -1;

// Function to insert an element into the linear queue
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Linear Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    lqueue[++rear] = value;
    printf("%d enqueued to linear queue\n", value);
}

// Function to remove an element from the linear queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Linear Queue Underflow\n");
        return;
    }
    printf("%d dequeued from linear queue\n", lqueue[front++]);
}

// Function to display elements of the linear queue
void displayLinearQueue() {
    if (front == -1 || front > rear) {
        printf("Linear Queue is empty\n");
        return;
    }
    printf("Linear Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", lqueue[i]);
    }
    printf("\n");
}

// Circular Queue Implementation 
// Circular queue array and front-rear pointers
int cqueue[SIZE];
int cfront = -1, crear = -1;

// Function to insert an element into the circular queue
void cEnqueue(int value) {
    if ((crear + 1) % SIZE == cfront) {
        printf("Circular Queue Overflow\n");
        return;
    }
    if (cfront == -1) cfront = 0;
    crear = (crear + 1) % SIZE;
    cqueue[crear] = value;
    printf("%d enqueued to circular queue\n", value);
}

// Function to remove an element from the circular queue
void cDequeue() {
    if (cfront == -1) {
        printf("Circular Queue Underflow\n");
        return;
    }
    printf("%d dequeued from circular queue\n", cqueue[cfront]);
    if (cfront == crear) {
        cfront = crear = -1; // Reset queue when last element is dequeued
    } else {
        cfront = (cfront + 1) % SIZE;
    }
}

// Function to display elements of the circular queue
void displayCircularQueue() {
    if (cfront == -1) {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = cfront;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == crear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

//  Main Function 
int main() {
    // Stack Operations
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();

    // Linear Queue Operations
    enqueue(1);
    enqueue(2);
    enqueue(3);
    displayLinearQueue();
    dequeue();
    displayLinearQueue();

    // Circular Queue Operations
    cEnqueue(11);
    cEnqueue(22);
    cEnqueue(33);
    displayCircularQueue();
    cDequeue();
    displayCircularQueue();

    return 0;
}
