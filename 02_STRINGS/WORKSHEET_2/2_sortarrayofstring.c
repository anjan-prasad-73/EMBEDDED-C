#include <stdio.h>

int main()
{
    char str[10][50];  // up to 10 strings, each up to 49 chars
    char temp[50];
    int n, i, j, k;

    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar(); // consume newline

    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++)
        gets(str[i]);

    // Bubble sort logic — compare and swap
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            // Manual string comparison
            k = 0;
            while (str[i][k] != '\0' && str[j][k] != '\0' && str[i][k] == str[j][k])
                k++;

            if (str[i][k] > str[j][k])
            {
                // Manual string swap
                k = 0;
                while (str[i][k] != '\0' || str[j][k] != '\0')
                {
                    temp[k] = str[i][k];
                    str[i][k] = str[j][k];
                    str[j][k] = temp[k];
                    k++;
                }
            }
        }
    }

    printf("\nStrings in alphabetical order:\n");
    for (i = 0; i < n; i++)
        printf("%s\n", str[i]);

    return 0;
}
