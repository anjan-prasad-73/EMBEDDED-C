#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int bufferSize;

    printf("Enter the maximum size of your input: ");
    if (scanf("%d", &bufferSize) != 1 || bufferSize <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    // Allocate buffer dynamically based on user input
    char *buffer = (char *)malloc(bufferSize * sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Clear input buffer before reading string
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter a string (up to %d characters): ", bufferSize - 1);
    // Use fgets to limit characters read and prevent overflow
    if (fgets(buffer, bufferSize, stdin) == NULL) {
        printf("Error reading input.\n");
        free(buffer);
        return 1;
    }

    // Remove newline character if present
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    printf("You entered: %s\n", buffer);

    // Example of safe string copy with validation
    char *safeCopy = (char *)malloc(bufferSize * sizeof(char));
    if (safeCopy != NULL) {
        strncpy(safeCopy, buffer, bufferSize - 1);
        safeCopy[bufferSize - 1] = '\0'; // Ensure null termination
        printf("Safe copy of string: %s\n", safeCopy);
        free(safeCopy);
    }

    // Free original buffer
    free(buffer);

    return 0;
}
