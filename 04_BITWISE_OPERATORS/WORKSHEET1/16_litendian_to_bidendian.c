#include <stdio.h>
#include <stdint.h>

uint32_t littleToBigEndian(uint32_t num) {
    uint32_t byte0, byte1, byte2, byte3;

    // Extract each byte
    byte0 = (num & 0x000000FF) >> 0;
    byte1 = (num & 0x0000FF00) >> 8;
    byte2 = (num & 0x00FF0000) >> 16;
    byte3 = (num & 0xFF000000) >> 24;

    // Rearrange bytes in reverse order
    return (byte0 << 24) | (byte1 << 16) | (byte2 << 8) | (byte3 << 0);
}

int main() {
    uint32_t num;

    printf("Enter a 32-bit integer (Little Endian): ");
    scanf("%u", &num);

    uint32_t bigEndian = littleToBigEndian(num);
    printf("Big Endian equivalent: %u\n", bigEndian);

    return 0;
}
