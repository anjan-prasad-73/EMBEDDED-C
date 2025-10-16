#include <stdio.h>

int main()
{
    char str[100], encoded[100];
    int i = 0, j = 0, count;
    
    printf("Enter string: ");
    gets(str);

    while (str[i] != '\0')
    {
        char current = str[i];
        count = 1;

        // Count consecutive occurrences
        while (str[i + 1] != '\0' && str[i] == str[i + 1])
        {
            count++;
            i++;
        }

        // Store character
        encoded[j++] = current;

        // Store count as characters
        int temp = count, digits[10], d = 0;

        // Handle multi-digit counts
        do {
            digits[d++] = temp % 10;
            temp /= 10;
        } while (temp > 0);

        // Add digits in reverse
        while (d > 0)
        {
            encoded[j++] = digits[--d] + '0';
        }
        i++;
    }

    encoded[j] = '\0';

    printf("Encoded string: %s\n", encoded);

    return 0;
}
