#include <stdio.h>

int main()
{
    char str[100];
    int i = 0, num = 0;

    printf("Enter numeric string: ");
    gets(str);

    // Traverse each character
    while (str[i] != '\0')
    {
        // Check if character is a digit
        if (str[i] >= '0' && str[i] <= '9')
        {
            // Multiply current number by 10 and add new digit
            num = num * 10 + (str[i] - '0');
        }
        else
        {
            printf("Invalid input! Non-digit character detected.\n");
            return 1;
        }
        i++;
    }

    printf("Converted integer: %d\n", num);
    return 0;
}

