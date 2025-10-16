#include <stdio.h>

// Recursive function to print binary
void decimalToBinary(int n) {
    if (n > 1)
        decimalToBinary(n / 2);
    printf("%d", n % 2);
}

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    printf("The Binary value is: ");
    decimalToBinary(num);
    printf("\n");

    return 0;
}
