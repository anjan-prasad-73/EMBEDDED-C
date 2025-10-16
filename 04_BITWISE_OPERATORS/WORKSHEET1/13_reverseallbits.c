#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t rev = 0;
    for(int i = 0; i < 32; i++) {
        rev <<= 1;          // Make space for next bit
        rev |= (n & 1);     // Add LSB of n to rev
        n >>= 1;            // Shift n to process next bit
    }
    return rev;
}

int main() {
    uint32_t num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    uint32_t reversed = reverseBits(num);
    printf("Original: %u\n", num);
    printf("Reversed: %u\n", reversed);

    return 0;
}
