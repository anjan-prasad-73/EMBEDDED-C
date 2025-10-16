/*Unions in Structures
Log Session a structure Student with a union inside it that can hold either an int roll_number or a char id[10].
Add a member char type to indicate which member is active.
Write functions to initialize and display the data for both types of students.*/

#include <stdio.h>
#include <string.h>

struct Student 
{
    char type;
    union {
        int roll_number;
        char id[10];
    } info;
};

void init_roll(struct Student *s, int roll) 
{
    s->type = 'R';
    s->info.roll_number = roll;
}

void init_id(struct Student *s, const char *id_str) 
{
    s->type = 'I';
    strncpy(s->info.id, id_str, sizeof(s->info.id) - 1);
    s->info.id[sizeof(s->info.id) - 1] = '\0';
}

void display(const struct Student *s) 
{
    if (s->type == 'R')
        printf("Roll Number: %d\n", s->info.roll_number);
    else if (s->type == 'I')
        printf("ID: %s\n", s->info.id);
    else
        printf("Unknown type\n");
}

int main() 
{
    struct Student s1, s2;
    init_roll(&s1, 12345);
    init_id(&s2, "ABC123");
    display(&s1);
    display(&s2);
    return 0;
}
