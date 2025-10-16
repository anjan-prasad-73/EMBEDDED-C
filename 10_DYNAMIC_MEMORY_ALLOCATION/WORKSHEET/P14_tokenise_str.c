/*Tokenize String Dynamically
Goal: Store each word of a sentence in dynamically allocated memory.
Activity:
Accept a sentence as input.
Use strtok() to split it into words.
Use malloc to copy each token into a new memory block.
Store them in a pointer array.
Print all words and free each block.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char sentence[200];
    char *tokens[50];
    int count = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    sentence[strcspn(sentence, "\n")] = '\0';

    char *token = strtok(sentence, " ");
    while (token != NULL && count < 50) 
    {
        tokens[count] = (char *)malloc(strlen(token) + 1);
        if (tokens[count] == NULL) 
        {
            printf("Memory allocation failed.\n");
            return 1;
        }
        strcpy(tokens[count], token);
        count++;
        token = strtok(NULL, " ");
    }

    printf("\nWords in the sentence:\n");
    for (int i = 0; i < count; i++) 
    {
        printf("%s\n", tokens[i]);
        free(tokens[i]);
    }

    return 0;
}
