#include <stdio.h>
int sequentialSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) if (arr[i] == key) return i;
    return -1;
}
int binarySearch(int arr[], int l, int r, int key) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == key) return m;
        else if (arr[m] < key) l = m + 1;
        else r = m - 1;
    }
    return -1;
}
// Tree search: Traverse BST (left if key < root, right if key > root)
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    printf("Sequential: %d\n", sequentialSearch(arr, 5, 10));
    printf("Binary: %d\n", binarySearch(arr, 0, 4, 10));
    return 0;
}
