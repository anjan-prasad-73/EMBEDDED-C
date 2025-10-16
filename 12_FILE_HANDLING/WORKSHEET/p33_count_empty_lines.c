/*Count how many empty (blank) lines are in a file.
Input: File: data.txt
Output: Blank lines: 1*/


#include <stdio.h>
#include <string.h>

int main() 
{
    char filename[100];
    char line[1024];
    int blank_lines = 0;

    printf("Enter file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        printf("Unable to open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) 
    {
        int only_spaces = 1;
        for (int i = 0; line[i] != '\0'; i++) 
        {
            if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\r') 
            {
                only_spaces = 0;
                break;
            }
        }
        if (only_spaces)
            blank_lines++;
    }

    fclose(fp);
    printf("Blank lines: %d\n", blank_lines);
    return 0;
}
