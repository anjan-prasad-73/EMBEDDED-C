/*Delete a file from the computer.
Input: File name: temp.txt
Output: File 'temp.txt' deleted.*/

#include <stdio.h>

int main() 
{
    char filename[100];
    printf("Enter the file name to delete: ");
    scanf("%99s", filename);
    if (remove(filename) == 0) 
    {
        printf("File '%s' deleted.\n", filename);
    } 
    else 
    {
        perror("Error deleting file");
    }
    return 0;
}
