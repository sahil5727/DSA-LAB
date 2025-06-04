 Balanced AVL tree

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// Utility to get height of the node
int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Utility to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;  // new node is added at leaf
    return node;
}

// Right rotate subtree rooted with y (for LL Case)
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotate subtree rooted with x (for RR Case)
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get balance factor of node
int getBalance(struct Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Insert a key into the AVL tree and balance it
struct Node* insert(struct Node* node, int key) {
    // 1. Normal BST insert
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // No duplicate keys
        return node;

    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get balance factor to check for unbalance
    int balance = getBalance(node);

    // 4. Balance the tree with rotation if needed

    // LL Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Print in-order traversal of the tree
void inOrder(struct Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Driver code
int main() {
    struct Node *root = NULL;

    // Insertions that cause all 4 rotation types
    root = insert(root, 30); // Insert first node
    root = insert(root, 20); // LL Case
    root = insert(root, 10); // Triggers LL (Right Rotate)
    root = insert(root, 40); // RR Case
    root = insert(root, 50); // Triggers RR (Left Rotate)
    root = insert(root, 25); // LR Case
    root = insert(root, 5);  // RL Case when added with proper keys

    printf("In-order traversal of the balanced AVL tree:\n");
    inOrder(root);
    printf("\n");

    return 0;
}
