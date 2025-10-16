/*Struct Array with Dynamic Allocation
Goal: Allocate memory for array of structs.

Activity:

Define a struct (e.g., name and age).
Ask user how many entries to store.
Allocate memory using malloc.
Accept values and display them.
Free the memory.*/
#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};

int main() 
{
    int n;
    struct Person *people;

    printf("How many people do you want to enter? ");
    scanf("%d", &n);

    people = (struct Person *)malloc(n * sizeof(struct Person));
    if (people == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) 
    {
        printf("Enter name for person %d: ", i + 1);
        scanf(" %[^\n]", people[i].name);
        printf("Enter age for person %d: ", i + 1);
        scanf("%d", &people[i].age);
    }

    printf("\nStored Data:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Person %d: %s, Age: %d\n", i + 1, people[i].name, people[i].age);
    }

    free(people);
    return 0;
}
