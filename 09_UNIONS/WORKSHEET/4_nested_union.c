/*Nested Union
Log Session a union called Number which contains an int and a nested union with a float and a char.
Write code to assign and access values from both the outer and inner union members.*/
#include <stdio.h>

union Number {
    int i;
    union {
        float f;
        char c;
    } nested;
};

int main() {
    union Number num;

    num.i = 100;
    printf("num.i = %d\n", num.i);

    num.nested.f = 3.14f;
    printf("num.nested.f = %.2f\n", num.nested.f);

    num.nested.c = 'A';
    printf("num.nested.c = %c\n", num.nested.c);

    printf("\nAfter assigning num.nested.c:\n");
    printf("num.i = %d\n", num.i);
    printf("num.nested.f = %.2f\n", num.nested.f);
    printf("num.nested.c = %c\n", num.nested.c);

    return 0;
}
