#include <stdio.h>

int main()
{
    char str1[100], str2[100];
    int i = 0, j = 0, len1 = 0, len2 = 0;

    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    // Find lengths manually
    while (str1[len1] != '\0') len1++;
    while (str2[len2] != '\0') len2++;

    // Step 1: Append str2 to str1
    for (i = 0; i < len2; i++)
        str1[len1 + i] = str2[i];
    str1[len1 + len2] = '\0';

    // Step 2: Copy first (len2) chars of str1 into str2
    for (i = 0; i < len2; i++)
        str2[i] = str1[i];
    str2[len2] = '\0';

    // Step 3: Shift remaining (str1) part left into str1
    for (i = 0; i < len1; i++)
        str1[i] = str1[len2 + i];
    str1[len1] = '\0';

    printf("After swapping:\n");
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);

    return 0;
}
