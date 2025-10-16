#include <stdio.h>
#include <stdint.h>

int count_set_bits_uint32(uint32_t x)
{
    int count = 0;
    while (x)
    {
      
       if (x&1)
       {
        count++;
       }       
         x=x>>1;
    }
    return count;
}

int main()
{
    float num;
    printf("Enter a floating-point number: ");
    scanf("%f", &num);

    // Reinterpret float as 32-bit unsigned integer
    uint32_t bits;
    // Safest way: use pointer casting
    bits = *((uint32_t*)&num);

    printf("\nFloat value: %f", num);
    printf("\nBinary representation (IEEE-754):\n");

    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (bits >> i) & 1);
        if (i == 31 || i == 23) printf(" "); // separate sign, exponent, mantissa
    }

    int count = count_set_bits_uint32(bits);
    printf("\n\nNumber of set bits in IEEE-754 representation: %d\n", count);

    return 0;
}
