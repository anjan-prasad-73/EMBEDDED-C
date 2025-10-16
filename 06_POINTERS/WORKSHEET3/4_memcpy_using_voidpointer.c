#include <stdio.h>
#include <stddef.h>

// Generic memory copy function
void mem_copy(void *dest, const void *src, size_t n) {
    char *d = (char *)dest;       // Convert to char* for byte-wise copy
    const char *s = (const char *)src;

    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
    }
}

int main() {
    // Test with integer array
    int src_int[] = {1, 2, 3, 4, 5};
    int dest_int[5] = {0};

    mem_copy(dest_int, src_int, sizeof(src_int));

    printf("Copied integer array: ");
    for (int i = 0; i < 5; i++) printf("%d ", dest_int[i]);
    printf("\n");

    // Test with float array
    float src_float[] = {1.1f, 2.2f, 3.3f};
    float dest_float[3] = {0};

    mem_copy(dest_float, src_float, sizeof(src_float));

    printf("Copied float array: ");
    for (int i = 0; i < 3; i++) printf("%.1f ", dest_float[i]);
    printf("\n");

    return 0;
}
