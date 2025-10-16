#include <stdio.h>
#include <string.h>

// Arithmetic functions
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

// Function that returns a pointer to the selected arithmetic function
int (*getOperation(const char *name))(int, int) {
    if (strcmp(name, "add") == 0) return add;
    else if (strcmp(name, "subtract") == 0) return subtract;
    else if (strcmp(name, "multiply") == 0) return multiply;
    else return NULL; // Invalid operation
}

int main() {
    int x, y;
    char opName[20];

    // Input numbers
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    // Input operation name
    printf("Enter operation name (add, subtract, multiply): ");
    scanf("%s", opName);

    // Get function pointer based on operation name
    int (*operation)(int, int) = getOperation(opName);

    if (operation != NULL) {
        int result = operation(x, y);  // Call function via pointer
        printf("Result: %d\n", result);
    } else {
        printf("Invalid operation name!\n");
    }

    return 0;
}
