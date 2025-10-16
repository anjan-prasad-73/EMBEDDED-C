/*Remove a specific line (by line number) from a file.
Input: File name: lines.txt
Line to remove: 2
Output: File now contains all lines except line 2.*/


#include <stdio.h>
#include <stdlib.h>

void remove_line(const char *filename, int line_to_remove) 
{
    FILE *fp = fopen(filename, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) 
    {
        printf("Error opening file.\n");
        return;
    }

    char buffer[1024];
    int current_line = 1;

    while (fgets(buffer, sizeof(buffer), fp)) 
    {
        if (current_line != line_to_remove)
            fputs(buffer, temp);
        current_line++;
    }

    fclose(fp);
    fclose(temp);
    remove(filename);
    rename("temp.txt", filename);
}

int main() 
{
    char filename[100];
    int num;

    printf("enter filename: ");
    scanf("%s", filename);

    printf("enter line number to remove: ");
    scanf("%d", &num);

    remove_line(filename, num);
    printf("File now contains all lines except line %d",num);

    return 0;
}
