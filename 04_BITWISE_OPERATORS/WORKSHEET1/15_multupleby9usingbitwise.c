#include <stdio.h>
#include <stdint.h>

int multiplyBy9(int num) {
    return (num << 3) + num; // (num * 8) + num = num * 9
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int result = multiplyBy9(num);
    printf("%d multiplied by 9 is: %d\n", num, result);

    return 0;
}
