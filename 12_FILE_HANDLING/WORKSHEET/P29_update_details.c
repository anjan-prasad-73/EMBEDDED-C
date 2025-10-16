/*Store employee details in a file and update them as needed.
Input: Add new employee: Name: John, Age: 25
Output: Employee added (info saved in file)*/

#include <stdio.h>

int main() 
{
    FILE *file = fopen("employees.txt", "a");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    char name[50] = "John";
    int age = 22;

    fprintf(file, "Name: %s, Age: %d\n", name, age);
    printf("Employee added\n");

    fclose(file);
    return 0;
}
