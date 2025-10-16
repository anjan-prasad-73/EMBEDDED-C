#include <stdio.h>

int intAdd(int a,int b){ return a+b; }
int intSub(int a,int b){ return a-b; }
float floatAdd(float a,float b){ return a+b; }
float floatSub(float a,float b){ return a-b; }

int main() {
    // [0] Arithmetic, [1] Bitwise (example)
    int (*intOps[])(int,int) = {intAdd,intSub};
    float (*floatOps[])(float,float) = {floatAdd,floatSub};

    int a=5, b=3;
    float x=5.5, y=2.5;

    printf("intAdd: %d\n", intOps[0](a,b));
    printf("intSub: %d\n", intOps[1](a,b));
    printf("floatAdd: %.2f\n", floatOps[0](x,y));
    printf("floatSub: %.2f\n", floatOps[1](x,y));

    return 0;
}
