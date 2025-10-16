#include <stdio.h>
#include <string.h>

char firstNonRepeatingChar(char* str) {
    int freq[256] = {0};
    int n = strlen(str);

    // Count frequency of each character
    for (int i = 0; i < n; i++) {
        freq[(unsigned char)str[i]]++;
    }

    // Find the first character with frequency 1
    for (int i = 0; i < n; i++) {
        if (freq[(unsigned char)str[i]] == 1) {
            return str[i];
        }
    }

    return '\0'; // If no non-repeating character exists
}

int main() {
    char str[] = "swiss";
    char result = firstNonRepeatingChar(str);
    if (result != '\0') {
        printf("Output: '%c'\n", result);  // Output: 'w'
    } else {
        printf("No non-repeating character found.\n");
    }
    return 0;
}
