/*Union Array
Declare an array of unions, each holding an int, a float, or a char.
Write a program to assign values of different types to each element and display them. Observe any issues.*/
#include <stdio.h>

union Value {
    int i;
    float f;
    char c;
};

int main() {
    union Value arr[3];

    arr[0].i = 10;
    arr[1].f = 3.14f;
    arr[2].c = 'A';

    printf("arr[0].i = %d\n", arr[0].i);
    printf("arr[1].f = %.2f\n", arr[1].f);
    printf("arr[2].c = %c\n", arr[2].c);

    return 0;
}
