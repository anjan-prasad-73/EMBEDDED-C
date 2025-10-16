#include <stdio.h>

int main() {
    char str[200], word[20];
    int i = 0, j, k, pos[20], count = 0, match;

    printf("Enter string: ");
    gets(str);
    printf("Enter word to search: ");
    gets(word);

    while (str[i] != '\0') {
        match = 1;
        for (k = 0; word[k] != '\0'; k++) {
            if (str[i + k] != word[k]) {
                match = 0;
                break;
            }
        }
        if (match && (str[i + k] == ' ' || str[i + k] == '\0')) {
            pos[count++] = i;
        }
        i++;
    }

    if (count == 0)
        printf("Word not found\n");
    else {
        printf("Found at positions: ");
        for (i = 0; i < count; i++)
            printf("%d ", pos[i]);
        printf("\n");
    }

    return 0;
}
