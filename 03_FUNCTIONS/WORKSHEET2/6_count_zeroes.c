#include <stdio.h>

// Recursive function to count zeros
int countZeros(int n) {
    if (n == 0) 
        return 0;

    int lastDigit = n % 10;
    if (lastDigit == 0)
        return 1 + countZeros(n / 10);
    else
        return countZeros(n / 10);
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Handle the special case when number is 0
    if (num == 0)
        printf("Number of zeros: 1\n");
    else
        printf("Number of zeros: %d\n", countZeros(num));

    return 0;
}
