#include <stdio.h>

// Function to swap two characters
void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Recursive function to generate permutations
void permute(char str[], int l, int r)
{
    int i;
    if (l == r)
    {
        // Print the permutation
        for (i = 0; str[i] != '\0'; i++)
            printf("%c", str[i]);
        printf("\n");
    }
    else
    {
        for (i = l; str[i] != '\0' && i <= r; i++)
        {
            swap(&str[l], &str[i]);         
            permute(str, l + 1, r);     
            swap(&str[l], &str[i]);        
        }
    }
}

int main()
{
    char str[100];
    int len = 0, i;

    printf("Enter string: ");
    gets(str);

    // Calculate string length manually
    while (str[len] != '\0')
        len++;

    printf("All permutations:\n");
    permute(str, 0, len - 1);

    return 0;
}
