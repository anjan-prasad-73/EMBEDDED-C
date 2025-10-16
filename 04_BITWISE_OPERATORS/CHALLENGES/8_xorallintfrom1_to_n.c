#include <stdio.h>

int xorFrom1ToN(int n) {
    switch (n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
    return 0; 
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int result = xorFrom1ToN(n);
    printf("XOR of all numbers from 1 to %d is: %d\n", n, result);

    return 0;
}
