//Practice error-checking after allocation.

#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t size = 1024L * 1024L * 1024L;
    void *ptr = malloc(size);

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Memory allocation of 1GB successful.\n");

    free(ptr);
    printf("Memory freed successfully.\n");

    return 0;
}
