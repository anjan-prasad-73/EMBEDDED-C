#include <stdio.h>
#include <stdint.h>

// Count set bits using Brian Kernighan's method
int countSetBits(uint32_t n) {
    int count = 0;
    while(n) {
        if (n&1)
        {
            count++;
        }
        n=n>>1;
    }
    return count;
}

int main() {
    uint32_t A, B;
    
    printf("Enter integer A: ");
    scanf("%u", &A);
    printf("Enter integer B: ");
    scanf("%u", &B);

    uint32_t xor = A ^ B; // XOR gives differing bits
    int flips = countSetBits(xor);

    printf("Number of bits to flip to convert A to B: %d\n", flips);

    return 0;
}
