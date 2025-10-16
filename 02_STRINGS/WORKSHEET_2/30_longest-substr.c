#include <stdio.h>

int main()
{
    char str1[100], str2[100];
    int i, j, k, len1 = 0, len2 = 0;
    int maxLen = 0, startIndex = 0;

    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    // Calculate lengths manually
    while (str1[len1] != '\0') len1++;
    while (str2[len2] != '\0') len2++;

    // Check all substrings of str1
    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < len2; j++)
        {
            k = 0;
            // Compare characters starting from str1[i] and str2[j]
            while ((i + k < len1) && (j + k < len2) && str1[i + k] == str2[j + k])
                k++;

            // Update maximum length found
            if (k > maxLen)
            {
                maxLen = k;
                startIndex = i;
            }
        }
    }

    // Print the longest common substring
    if (maxLen > 0)
    {
        printf("Longest common substring: ");
        for (i = 0; i < maxLen; i++)
            printf("%c", str1[startIndex + i]);
        printf("\n");
    }
    else
    {
        printf("No common substring found.\n");
    }


    return 0;
}
