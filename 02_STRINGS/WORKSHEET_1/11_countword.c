#include <stdio.h>

int main() {
    char str[100];
    int i = 0, words = 0, inWord = 0;

    printf("Enter string: ");
    gets(str);

    while (str[i] != '\0') {
        if (str[i] != ' ' && inWord == 0) {
            inWord = 1;
            words++;
        } else if (str[i] == ' ') {
            inWord = 0;
        }
        i++;
    }

    printf("Total words: %d\n", words);
    return 0;
}
