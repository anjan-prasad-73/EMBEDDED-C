/*Accessing Union Members
Using the union from exercise 1, assign values to more than one member at a time and print all members.
Observe which value is retained and explain why.*/
#include <stdio.h>
#include <string.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    union Data data;

    data.i = 42;
    printf("After assigning int:\n");
    printf("i = %d\n", data.i);
    printf("f = %.2f\n", data.f);
    printf("str = %s\n\n", data.str);

    data.f = 3.14f;
    printf("After assigning float:\n");
    printf("i = %d\n", data.i);
    printf("f = %.2f\n", data.f);
    printf("str = %s\n\n", data.str);

    strcpy(data.str, "Union");
    printf("After assigning string:\n");
    printf("i = %d\n", data.i);
    printf("f = %.2f\n", data.f);
    printf("str = %s\n", data.str);

    return 0;
}
