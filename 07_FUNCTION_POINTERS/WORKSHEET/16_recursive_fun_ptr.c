#include <stdio.h>

int (*fact)(int); // Function pointer declaration

int factorial(int n) {
    if(n<=1) return 1;
    return n * fact(n-1); // Recursive call via pointer
}

int main() {
    fact = factorial; // Assign function pointer

    int n = 5;
    printf("Factorial of %d: %d\n", n, fact(n));

    return 0;
}
