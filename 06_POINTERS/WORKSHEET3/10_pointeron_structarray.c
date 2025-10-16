#include <stdio.h>
#include <stdint.h>

struct Peripheral {
    uint8_t status;
    uint8_t control;
    uint16_t data;
};

int main() {
    // Declare an array of 5 peripherals
    struct Peripheral peripherals[5] = {
        {0x01, 0x10, 100},
        {0x02, 0x20, 200},
        {0x03, 0x30, 300},
        {0x04, 0x40, 400},
        {0x05, 0x50, 500}
    };

    // Pointer to struct Peripheral
    struct Peripheral *p = peripherals;

    // Traverse and modify using pointer arithmetic
    for (int i = 0; i < 5; i++, p++) {
        printf("Peripheral %d before modification: status=0x%X, control=0x%X, data=%d\n",
               i, p->status, p->control, p->data);

        // Modify the registers
        p->status += 0x10;
        p->control ^= 0xFF;
        p->data += 100;

        printf("Peripheral %d after modification: status=0x%X, control=0x%X, data=%d\n\n",
               i, p->status, p->control, p->data);
    }

    return 0;
}
