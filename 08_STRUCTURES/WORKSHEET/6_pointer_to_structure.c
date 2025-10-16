#include <stdio.h>
#include <stdlib.h>

// Define a structure
struct Device {
    int controlReg;
    int statusReg;
    int dataReg;
};

int main() {
    // Declare a pointer to the structure
    struct Device *devPtr;

    // Allocate memory for the structure
    devPtr = (struct Device *)malloc(sizeof(struct Device));

    // Always check if malloc succeeded
    if (devPtr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Assign values using the arrow operator
    devPtr->controlReg = 0x01; // e.g., turn on device
    devPtr->statusReg  = 0x00; // clear status
    devPtr->dataReg    = 100;  // some data

    // Print structure member values
    printf("Control Register: %d\n", devPtr->controlReg);
    printf("Status Register : %d\n", devPtr->statusReg);
    printf("Data Register   : %d\n", devPtr->dataReg);

    // Free allocated memory
    free(devPtr);

    return 0;
}
