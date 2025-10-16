#include <stdio.h>

// Function to check if a number is perfect
int isPerfect(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0)
            sum += i;
    }
    return sum == n;
}

// Function to print perfect numbers in range
void printPerfectNumbers(int start, int end) {
    printf("The perfect numbers between %d to %d are: ", start, end);
    for (int i = start; i <= end; i++) {
        if (isPerfect(i))
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int start = 1, end = 100;
    printPerfectNumbers(start, end);
    return 0;
}
