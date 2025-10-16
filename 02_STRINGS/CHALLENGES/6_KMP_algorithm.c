#include <stdio.h>
#include <string.h>

// Function to compute LPS array
void computeLPS(char* pattern, int m, int* lps) {
    int len = 0;
    lps[0] = 0;  // LPS of first character is 0
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];  // Use previous LPS
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP search function
void KMPSearch(char* pattern, char* text) {
    int m = strlen(pattern);
    int n = strlen(text);

    int lps[m];
    computeLPS(pattern, m, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];  // Continue searching
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    char text[] = "ababcabcab";
    char pattern[] = "abc";

    KMPSearch(pattern, text);

    return 0;
}
