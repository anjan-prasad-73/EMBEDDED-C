#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool areAnagrams(char* str1, char* str2) {
    if (strlen(str1) != strlen(str2)) return false;

    int freq[256] = {0}; // Frequency array for all ASCII characters

    // Count frequency for str1 and str2
    for (int i = 0; str1[i] != '\0'; i++) {
        freq[(unsigned char)str1[i]]++;   // Increment for str1
        freq[(unsigned char)str2[i]]--;   // Decrement for str2
    }

    // Check if all frequencies are 0
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) return false;
    }

    return true;
}

int main() {
    char str1[] = "listen";
    char str2[] = "silent";

    if (areAnagrams(str1, str2)) {
        printf("Output: true\n");  // Output: true
    } else {
        printf("Output: false\n");
    }

    return 0;
}
