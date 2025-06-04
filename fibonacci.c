// Fibonacci Series using Recursion
#include <stdio.h>

// Recursive function to calculate Fibonacci number at position n
int fibonacci(int n) {
    if (n == 0)
        return 0; // Base case: 0th Fibonacci number is 0
    else if (n == 1)
        return 1; // Base case: 1st Fibonacci number is 1
    else
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive relation: F(n) = F(n-1) + F(n-2)
}

int main() {
    int terms;

    // Asking the user to enter the number of terms for the Fibonacci series
    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    // Displaying the Fibonacci series up to the entered number of terms
    printf("Fibonacci Series up to %d terms:\n", terms);
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i)); // Printing each term of the series
    }
    printf("\n"); // New line after the series

    return 0;
}


