#include <stdio.h>

int main()
{
    char str1[100], str2[100];
    int i, j, k, len1 = 0, len2 = 0, isRotation = 0;

    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    // Step 1: Find lengths manually
    for (i = 0; str1[i] != '\0'; i++)
        len1++;
    for (i = 0; str2[i] != '\0'; i++)
        len2++;

    // If lengths differ, not a rotation
    if (len1 != len2)
    {
        printf("No\n");
        return 0;
    }

    // Step 2: Try all possible rotations
    for (i = 0; i < len1; i++)
    {
        isRotation = 1;

        // Compare rotated version
        for (j = 0; j < len1; j++)
        {
            k = (i + j) % len1; // Circular shift
            if (str1[k] != str2[j])
            {
                isRotation = 0;
                break;
            }
        }

        if (isRotation)
            break;
    }

    if (isRotation)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
