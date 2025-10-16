#include <stdio.h>

int main()
{
    char str[100], result[100];
    int i = 0, j = 0;

    printf("Enter string: ");
    gets(str);

    while (str[i] != '\0')
    {
        // Remove 'b'
        if (str[i] == 'b')
        {
            i++;
            continue;
        }

        // Remove substring "ac"
        if (str[i] == 'a' && str[i + 1] == 'c')
        {
            i += 2; // skip both characters
            continue;
        }

        // Copy remaining characters to result
        result[j++] = str[i++];
    }

    result[j] = '\0';

    printf("Modified string: %s\n", result);

    return 0;
}
