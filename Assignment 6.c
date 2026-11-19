#include <stdio.h>

unsigned long long factorialIterative(int n) {
    unsigned long long result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

unsigned long long factorialRecursive(int n) {
    if (n <= 1) {
        return 1;
    }

    return (unsigned long long)n * factorialRecursive(n - 1);
}

int main(void) {
    int number;

    printf("Enter a non-negative integer: ");
    if (scanf("%d", &number) != 1 || number < 0) {
        printf("Invalid input. Enter a non-negative integer.\n");
        return 1;
    }

    printf("Factorial without recursion = %llu\n",
           factorialIterative(number));
    printf("Factorial with recursion = %llu\n",
           factorialRecursive(number));

    return 0;
}