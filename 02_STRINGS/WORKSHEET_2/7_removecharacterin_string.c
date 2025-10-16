#include <stdio.h>

int main()
{
    char str1[100], str2[100];
    char result[100];
    int i, j, k, found;

    // Input strings
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    k = 0; // Index for result string

    // Traverse each character of str1
    for (i = 0; str1[i] != '\0'; i++)
    {
        found = 0; // Assume character not found in str2

        // Compare with each character of str2
        for (j = 0; str2[j] != '\0'; j++)
        {
            if (str1[i] == str2[j])
            {
                found = 1; // Character exists in str2
                break;
            }
        }

        // If not found, keep it in result
        if (!found)
        {
            result[k] = str1[i];
            k++;
        }
    }

    result[k] = '\0'; // End result string
    printf("Resultant string: %s\n", result);

    return 0;
}
