#include <stdio.h>
#include <math.h>

// Function to calculate power: a^b
float power(float a, float b) {
    return pow(a, b);
}

// Function to calculate modulo: a % b
float modulo(float a, float b) {
    if(b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return fmod(a, b);
}

// Function to calculate square root of a
float squareRoot(float a, float b) { // b is ignored for sqrt
    if(a < 0) {
        printf("Error: Negative input for square root!\n");
        return 0;
    }
    return sqrt(a);
}

// Function to print menu
void printMenu() {
    printf("Choose operation:\n");
    printf("0: Power (a^b)\n");
    printf("1: Modulo (a %% b)\n");
    printf("2: Square Root (sqrt(a))\n");
}

int main() {
    float a, b, result;
    int choice;

    // Array of function pointers
    float (*operations[])(float, float) = {power, modulo, squareRoot};

    printf("Enter two numbers (for square root, second number will be ignored): ");
    scanf("%f %f", &a, &b);

    printMenu();
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice >=0 && choice <=2) {
        result = operations[choice](a, b);
        printf("Result: %.2f\n", result);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
