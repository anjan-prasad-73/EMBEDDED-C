/* Implement Custom strdup()
Goal: Practice duplicating a string using dynamic memory.

Activity:

Log Session a function that takes a string as input.
Allocate memory for a copy of the string.
Copy character by character.
Return the copied string.
Call this function and display the result.
Free the copied string.
*/
#include <stdio.h>
#include <stdlib.h>

char* custom_strdup(const char *src) 
{
    int length = 0;
    while (src[length] != '\0') 
    {
        length++;
    }

    char *copy = (char *)malloc((length + 1) * sizeof(char));
    if (copy == NULL) 
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    for (int i = 0; i <= length; i++) 
    {
        copy[i] = src[i];
    }

    return copy;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    int i = 0;
    while (input[i] != '\0') 
    {
        if (input[i] == '\n') 
        {
            input[i] = '\0';
            break;
        }
        i++;
    }

    char *copiedString = custom_strdup(input);

    if (copiedString != NULL) 
    {
        printf("Copied string: %s\n", copiedString);
        free(copiedString);
    }

    return 0;
}
