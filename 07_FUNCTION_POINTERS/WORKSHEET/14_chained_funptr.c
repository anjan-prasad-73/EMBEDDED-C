#include <stdio.h>

int doubleValue(int x) { return x*2; }
int increment(int x) { return x+1; }
int square(int x) { return x*x; }

int main() {
    int (*pipeline[])(int) = {doubleValue, increment, square};

    int value = 3;
    printf("Initial value: %d\n", value);

    for(int i=0; i<3; i++) {
        value = pipeline[i](value);
        printf("After step %d: %d\n", i+1, value);
    }

    return 0;
}
