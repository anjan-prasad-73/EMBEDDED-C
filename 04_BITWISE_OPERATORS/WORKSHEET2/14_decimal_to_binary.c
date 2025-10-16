#include <stdio.h>

int main() {
    unsigned int num;
    char binary[32];
    int i = 0;

    printf("Enter a decimal number: ");
    scanf("%u", &num);

    if (num == 0) {
        printf("Binary representation: 0\n");
        return 0;
    }

    // Extract bits using bitwise AND and store in array
    while (num > 0) {
        binary[i++] = (num & 1) + '0'; // Get LSB
        num >>= 1;                      // Shift right
    }

    printf("Binary representation: ");
    // Print bits in reverse order
    for (int j = i - 1; j >= 0; j--) {
        putchar(binary[j]);
    }
    printf("\n");

    return 0;
}
