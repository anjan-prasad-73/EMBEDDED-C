#include <stdio.h>

int main() {
    char str[100], word[20], temp[100];
    int i = 0, j = 0, k, t = 0, match;

    printf("Enter string: ");
    gets(str);
    printf("Enter word to remove: ");
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
            i += k;
            if (str[i] == ' ') i++;
        } else {
            temp[t++] = str[i++];
        }
    }
    temp[t] = '\0';
    printf("Modified: %s\n", temp);
    return 0;
}
