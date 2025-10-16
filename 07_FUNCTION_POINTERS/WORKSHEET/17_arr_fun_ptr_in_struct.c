#include <stdio.h>

typedef struct {
    int (*ops[3])(int,int);
} Calculator;

int add(int a,int b){ return a+b; }
int sub(int a,int b){ return a-b; }
int mul(int a,int b){ return a*b; }

int main() {
    Calculator calc = {add, sub, mul};

    int x=4, y=5;
    printf("Add: %d\n", calc.ops[0](x,y));
    printf("Sub: %d\n", calc.ops[1](x,y));
    printf("Mul: %d\n", calc.ops[2](x,y));

    return 0;
}
