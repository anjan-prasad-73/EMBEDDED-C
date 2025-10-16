/*Anonymous Union
Declare an anonymous union inside a structure.
Initialize and access its members without using a union name.
Demonstrate how this simplifies access in code.*/
#include <stdio.h>

struct Data {
    int id;
    union {
        int i;
        float f;
        char c;
    }; 
};

int main() {
    struct Data d = { .id = 1, .i = 42 };

    printf("id = %d\n", d.id);
    printf("i = %d\n", d.i);

    d.f = 3.14f;  
    printf("f = %.2f\n", d.f);

    d.c = 'Z';   
    printf("c = %c\n", d.c);

    return 0;
}
