#include <stdio.h>

int main() {
    char str[100], word[20];
    int i = 0, j = 0, k, found = -1;

    printf("Enter string: ");
    gets(str);
    printf("Enter word: ");
    gets(word);

    while (str[i] != '\0') {
        k = i;
        j = 0;
        while (str[k] == word[j] && word[j] != '\0') {
            k++; j++;
        }
        if (word[j] == '\0') {
            found = i;
            break;
        }
        i++;
    }

    if (found != -1)
        printf("Found at position %d\n", found);
    else
        printf("Not found\n");
    return 0;
}
