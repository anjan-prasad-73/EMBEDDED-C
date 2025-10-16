#include <stdio.h>

int main() {
    char str[100], ch;
    int i, pos = -1;

    printf("Enter string: ");
    gets(str);
    printf("Find character: ");
    scanf(" %c", &ch);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            pos = i;
            break;
        }
    }

    if (pos != -1)
        printf("First occurrence at position: %d\n", pos);
    else
        printf("Character not found\n");

    return 0;
}
