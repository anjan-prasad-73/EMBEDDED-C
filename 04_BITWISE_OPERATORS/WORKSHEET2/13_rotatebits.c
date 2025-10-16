#include <stdio.h>
#include <stdint.h>

// Rotate left
uint32_t rotateLeft(uint32_t n, int d) {
    return (n << d) | (n >> (32 - d));
}

// Rotate right
uint32_t rotateRight(uint32_t n, int d) {
    return (n >> d) | (n << (32 - d));
}

int main() {
    uint32_t num;
    int positions;
    char dir;

    printf("Enter a number: ");
    scanf("%u", &num);
    printf("Enter number of positions to rotate: ");
    scanf("%d", &positions);
    printf("Enter direction (L for left, R for right): ");
    scanf(" %c", &dir);

    uint32_t result;
    if (dir == 'L' || dir == 'l') {
        result = rotateLeft(num, positions);
    } else if (dir == 'R' || dir == 'r') {
        result = rotateRight(num, positions);
    } else {
        printf("Invalid direction!\n");
        return 1;
    }

    printf("Result after rotation: %u\n", result);
    return 0;
}
