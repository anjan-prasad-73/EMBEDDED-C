#include <stdio.h>

// Recursive function to interleave two strings
void interleave(char str1[], char str2[], char result[], int i, int j, int k)
{
    // If both strings are finished, print the result
    if (str1[i] == '\0' && str2[j] == '\0')
    {
        result[k] = '\0';
        printf("%s\n", result);
        return;
    }

    // Take next char from str1, if available
    if (str1[i] != '\0')
    {
        result[k] = str1[i];
        interleave(str1, str2, result, i + 1, j, k + 1);
    }

    // Take next char from str2, if available
    if (str2[j] != '\0')
    {
        result[k] = str2[j];
        interleave(str1, str2, result, i, j + 1, k + 1);
    }
}
int main()
{
    char str1[50], str2[50], result[100];

    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    printf("All interleavings:\n");
    interleave(str1, str2, result, 0, 0, 0);

    return 0;
}
