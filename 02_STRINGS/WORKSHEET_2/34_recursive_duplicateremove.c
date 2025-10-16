#include <stdio.h>
#include <string.h>

// Function to recursively remove adjacent duplicates
void removeAdjDuplicates(char* str) {
    int n = strlen(str);
    if (n == 0 || n == 1) return;

    char result[n + 1];  // temporary string
    int i = 0, j = 0;
    int changed = 0;

    while (i < n) {
        if (i < n - 1 && str[i] == str[i + 1]) {
            // Skip all adjacent duplicates
            char dup = str[i];
            while (i < n && str[i] == dup) i++;
            changed = 1;  // mark that change happened
        } else {
            // Keep the character
            result[j++] = str[i++];
        }
    }

    result[j] = '\0';

    // Copy result back to str
    strcpy(str, result);

    // Recur if any change occurred
    if (changed) {
        removeAdjDuplicates(str);
    }
}

int main() {
    char str[] = "azxxzy";
    removeAdjDuplicates(str);
    printf("Output: %s\n", str);  // Output: ay
    return 0;
}
