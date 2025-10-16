/*
Change a particular line in a file to some new text.
Input: File name: lines.txt
Line number: 3
New text: This line has been changed!
Output: File now contains new text at line 3.
*/

#include <stdio.h>
#include <string.h>

int main() 
{
    FILE *file = fopen("lines.txt", "r");
    if (file == NULL) 
    {
        perror("Unable to open file");
        return 1;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) 
    {
        perror("Unable to create temp file");
        fclose(file);
        return 1;
    }

    char line[1000];
    int current = 1;
    int target = 3;

    while (fgets(line, sizeof(line), file)) 
    {
        if (current == target) 
        {
            fprintf(temp, "hi\n");
        } 
        else 
        {
            fputs(line, temp);
        }
        current++;
    }

    fclose(file);
    fclose(temp);

    remove("lines.txt");
    rename("temp.txt", "lines.txt");

    printf("Line %d updated\n", target);
    return 0;
}
