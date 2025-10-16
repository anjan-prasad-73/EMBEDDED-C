#include <stdio.h>

int main() {
    int a = 5;      // Normal integer
    int *p = &a;    // Pointer to integer
    int **pp = &p;  // Pointer to pointer

    printf("Value of a: %d\n", a);        // Direct access
    printf("Value via *p: %d\n", *p);    // Access through single pointer
    printf("Value via **pp: %d\n", **pp);// Access through pointer to pointer

    // Optional: Print addresses
    printf("\nAddress of a: %p\n", (void*)&a);
    printf("Address stored in p: %p\n", (void*)p);
    printf("Address stored in pp: %p\n", (void*)pp);
    printf("Value via *pp (address of a): %p\n", (void*)*pp);

    return 0;
}
