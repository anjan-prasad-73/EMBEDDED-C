#include <stdio.h>

int main() {
    char str[100], ch;
    int i, last = -1;

    printf("Enter string: ");
    gets(str);
    printf("Enter character to remove: ");
    scanf(" %c", &ch);

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == ch)
            last = i;

    if (last != -1) {
        for (i = last; str[i] != '\0'; i++)
            str[i] = str[i + 1];
    }

    printf("After removal: %s\n", str);
    return 0;
}
