#include <stdio.h>
#define MAX 10
int heap[MAX], size = 0;

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }
void heapifyUp(int index) {
    while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}
void insert(int item) {
    if (size == MAX) printf("Heap Full!\n");
    else { heap[size++] = item; heapifyUp(size - 1); }
}
void display() { for (int i = 0; i < size; i++) printf("%d ", heap[i]); }
int main() {
    insert(30); insert(20); insert(15); insert(5); insert(10); insert(12);
    display();
    return 0;
}
