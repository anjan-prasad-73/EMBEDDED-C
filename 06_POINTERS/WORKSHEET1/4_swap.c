#include <stdio.h>

// Function to swap two numbers using pointers
void swap(int *a, int *b) {
    int temp = *a;  // store value of a
    *a = *b;        // assign value of b to a
    *b = temp;      // assign stored value to b
}

int main() {
    int x = 10, y = 20;

    printf("Before swap: x = %d, y = %d\n", x, y);

    swap(&x, &y);  // Pass addresses of x and y

    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}
