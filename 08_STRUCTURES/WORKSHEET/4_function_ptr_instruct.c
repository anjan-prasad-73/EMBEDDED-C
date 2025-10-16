#include <stdio.h>
#include <string.h>

// Define typedef for function pointer types
typedef void (*InitFunc)(void);
typedef void (*WriteFunc)(const char *);
typedef void (*ReadFunc)(void);

// Define a structure representing a generic device driver
typedef struct {
    char name[20];
    InitFunc init;
    WriteFunc write;
    ReadFunc read;
} DeviceDriver;

// Implement different device behaviors
void LCD_Init(void) {
    printf("LCD Initialized.\n");
}

void LCD_Write(const char *msg) {
    printf("LCD Display: %s\n", msg);
}

void LCD_Read(void) {
    printf("LCD Read: Display buffer data.\n");
}

void UART_Init(void) {
    printf("UART Initialized.\n");
}

void UART_Write(const char *msg) {
    printf("UART Transmit: %s\n", msg);
}

void UART_Read(void) {
    printf("UART Read: Received data.\n");
}

int main() {
    // Create two device driver instances
    DeviceDriver lcdDriver = {
        .name = "LCD Driver",
        .init = LCD_Init,
        .write = LCD_Write,
        .read = LCD_Read
    };

    DeviceDriver uartDriver = {
        .name = "UART Driver",
        .init = UART_Init,
        .write = UART_Write,
        .read = UART_Read
    };

    // Choose device dynamically (simulate condition)
    DeviceDriver *activeDriver;

    int choice;
    printf("Select Device (1 = LCD, 2 = UART): ");
    scanf("%d", &choice);

    if (choice == 1)
        activeDriver = &lcdDriver;
    else
        activeDriver = &uartDriver;

    // Use the selected driver
    printf("\nUsing %s\n", activeDriver->name);
    activeDriver->init();
    activeDriver->write("Hello, Embedded World!");
    activeDriver->read();

    return 0;
}
