#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a single int using double pointer
void allocateInt(int **ptr) {
    *ptr = (int *)malloc(sizeof(int));  // Allocate memory
    if (*ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    **ptr = 42;  // Assign value
}

int main() {
    int *p = NULL;  // Pointer to int
    int **pp = &p;  // Double pointer

    allocateInt(pp);  // Pass double pointer to function

    printf("Value of dynamically allocated int: %d\n", *p);

    free(p);  // Free allocated memory
    return 0;
}
