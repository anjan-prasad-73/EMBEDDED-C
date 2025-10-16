#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool areAnagrams(char *str1, char *str2) {
    if (strlen(str1) != strlen(str2))
        return false;

    int freq[256] = {0};  // ASCII characters

    for (int i = 0; str1[i] != '\0'; i++) {
        freq[(unsigned char)str1[i]]++;   // increment for str1
        freq[(unsigned char)str2[i]]--;   // decrement for str2
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0)
            return false;
    }
    return true;
}

int main() {
    char str1[] = "spare";
    char str2[] = "pears";

    if (areAnagrams(str1, str2)) {
        printf("%s and %s are Anagram.\n", str1, str2);
    } else {
        printf("%s and %s are not Anagram.\n", str1, str2);
    }

    return 0;
}
