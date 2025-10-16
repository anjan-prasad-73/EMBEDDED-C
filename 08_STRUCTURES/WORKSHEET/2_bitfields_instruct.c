#include <stdio.h>

// Define an 8-bit status register using bit-fields
struct StatusRegister {
    unsigned char error : 1;   // Bit 0 → Error flag
    unsigned char ready : 1;   // Bit 1 → Ready flag
    unsigned char mode  : 2;   // Bits 2-3 → Mode (00: IDLE, 01: RUN, 10: SLEEP, 11: ERROR)
    unsigned char reserved : 4;// Bits 4-7 → Unused / reserved
};

int main(void) {
    struct StatusRegister reg = {0};  // All bits start as 0

    // Set flags individually (no bitwise operators needed)
    reg.error = 1;
    reg.ready = 0;
    reg.mode = 2;   // Example: Mode = "SLEEP"

    printf("Status Register:\n");
    printf("Error = %d\n", reg.error);
    printf("Ready = %d\n", reg.ready);
    printf("Mode  = %d\n", reg.mode);

    // Toggle a flag (compiler automatically shifts bits)
    reg.ready = !reg.ready;

    printf("\nAfter toggling Ready:\n");
    printf("Error = %d, Ready = %d, Mode = %d\n",
           reg.error, reg.ready, reg.mode);

    printf("\nTotal size of structure: %lu byte(s)\n", sizeof(reg));

    return 0;
}
