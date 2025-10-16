#include <stdio.h>

int main()
{
    char list[10][50]; // up to 10 strings, each max 49 chars
    char word[50];
    int n, i, j, k, found, match;

    printf("Enter number of strings in list: ");
    scanf("%d", &n);
    getchar(); // consume newline

    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++)
        gets(list[i]);

    printf("Enter word to match: ");
    gets(word);

    printf("Matching strings:\n");

    // Traverse each string in the list
    for (i = 0; i < n; i++)
    {
        match = 1;

        // Check if all chars of 'word' exist in list[i]
        for (j = 0; word[j] != '\0'; j++)
        {
            found = 0;
            for (k = 0; list[i][k] != '\0'; k++)
            {
                if (word[j] == list[i][k])
                {
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                match = 0;
                break;
            }
        }

        if (match)
            printf("%s\n", list[i]);
    }

    return 0;
}
