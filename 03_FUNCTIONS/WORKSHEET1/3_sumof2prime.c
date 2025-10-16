#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to check if a number can be expressed as sum of two primes
void sumOfTwoPrimes(int n) {
    bool found = false;

    for (int i = 2; i <= n / 2; i++) {
        if (isPrime(i) && isPrime(n - i)) {
            printf("%d = %d + %d\n", n, i, n - i);
            found = true;
        }
    }

    if (!found) {
        printf("%d cannot be expressed as sum of two prime numbers.\n", n);
    }
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    sumOfTwoPrimes(n);

    return 0;
}
