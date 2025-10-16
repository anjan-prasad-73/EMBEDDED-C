#include <stdio.h>
#include <stdint.h>

uint32_t setbits(uint32_t x, int p, int n, uint32_t y) {
    // Step 1: Create a mask for n bits at position p
    uint32_t mask = ((1U << n) - 1) << (p - n + 1);
    
    // Step 2: Clear those n bits in x
    x &= ~mask;
    
    // Step 3: Take rightmost n bits of y and shift them to position p
    uint32_t y_bits = (y & ((1U << n) - 1)) << (p - n + 1);
    
    // Step 4: Combine x with the new bits
    return x | y_bits;
}

int main() {
    uint32_t x, y;
    int p, n;

    printf("Enter x: ");
    scanf("%u", &x);
    printf("Enter y: ");
    scanf("%u", &y);
    printf("Enter position p (0-based from right): ");
    scanf("%d", &p);
    printf("Enter number of bits n: ");
    scanf("%d", &n);

    uint32_t result = setbits(x, p, n, y);
    printf("Result after setting bits: %u\n", result);

    return 0;
}
