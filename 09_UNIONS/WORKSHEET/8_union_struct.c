/*Structure Inside a Union
Define a union that contains a structure (for example, struct { int x, y; }) and an int.
Write a program to set and access the structure members through the union.*/

#include <stdio.h>

union U {
    struct {
        int x;
        int y;
    } point;
    int i;
};

int main() {
    union U u;

    u.point.x = 10;
    u.point.y = 20;
    printf("point.x = %d, point.y = %d\n", u.point.x, u.point.y);

    u.i = 100;
    printf("i = %d\n", u.i);
    printf("After setting i:\n");
    printf("point.x = %d, point.y = %d\n", u.point.x, u.point.y);

    return 0;
}
