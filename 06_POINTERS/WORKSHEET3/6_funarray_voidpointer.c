#include <stdio.h>

// Device operation functions
void init(void) {
    printf("Device initialized.\n");
}

void start(void) {
    printf("Device started.\n");
}

void stop(void) {
    printf("Device stopped.\n");
}

int main() {
    // Array of function pointers
    void (*commands[])(void) = {init, start, stop};
    int num_commands = sizeof(commands) / sizeof(commands[0]);

    // Execute all commands sequentially
    for (int i = 0; i < num_commands; i++) {
        commands[i]();  // Call function via pointer
    }

    // Example: execute command based on user input
    int choice;
    printf("Enter command index (0:init, 1:start, 2:stop): ");
    scanf("%d", &choice);

    if (choice >= 0 && choice < num_commands) {
        commands[choice]();  // Execute selected command
    } else {
        printf("Invalid command.\n");
    }

    return 0;
}
