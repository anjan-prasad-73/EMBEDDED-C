/*Add up numbers given as command line arguments and write the answer into a file.
Input: Arguments: 3 4 5, Output file: sum.txt
Output: sum.txt contains: 12*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    int sum = 0;
    for (int i = 1; i < argc; i++) 
        sum += atoi(argv[i]);
    
    FILE *file = fopen("sum.txt", "w");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    fprintf(file, "%d\n", sum);
    fclose(file);

    return 0;
}
