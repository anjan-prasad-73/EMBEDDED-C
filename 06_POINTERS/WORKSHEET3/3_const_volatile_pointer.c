#include <stdint.h>
#include <stdio.h>

#define REG_BASE 0x40000000

int main() {
    // Pointer to a hardware register
    volatile uint32_t *reg_modifiable = (uint32_t *)REG_BASE;         // Read/Write
    const uint32_t *reg_readonly = (const uint32_t *)REG_BASE;        // Read-only
    const volatile uint32_t *reg_const_volatile = (const volatile uint32_t *)REG_BASE; // Read-only, may change externally

    // Example usage:

    // 1. Write to modifiable register (OK)
    *reg_modifiable = 0x1234;  
    printf("Wrote 0x1234 to reg_modifiable\n");

    // 2. Read from modifiable register (OK)
    uint32_t val1 = *reg_modifiable;
    printf("Read from reg_modifiable: 0x%X\n", val1);

    // 3. Read from readonly register (OK)
    uint32_t val2 = *reg_readonly;
    printf("Read from reg_readonly: 0x%X\n", val2);

    // 4. Attempt to write to readonly register (Error!)
    // *reg_readonly = 0x5678; // Compiler will prevent this

    // 5. Read from const volatile register (OK)
    uint32_t val3 = *reg_const_volatile;
    printf("Read from reg_const_volatile: 0x%X\n", val3);

    // 6. Attempt to write to const volatile register (Error!)
    // *reg_const_volatile = 0x9ABC; // Compiler error

    return 0;
}
