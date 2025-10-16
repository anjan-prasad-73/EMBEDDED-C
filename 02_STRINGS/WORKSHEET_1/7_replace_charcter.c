#include <stdio.h>

int main() {
    char str[] = "banana";
    char oldChar = 'a';
    char newChar = 'o';
    int i = 0;

    // Traverse each character manually
    while (str[i] != '\0') {
        if (str[i] == oldChar)
            str[i] = newChar;
        i++;
    }

    // Print modified string
    i = 0;
    while (str[i] != '\0') {
        printf("%c", str[i]);
        i++;
    }

    return 0;
}
