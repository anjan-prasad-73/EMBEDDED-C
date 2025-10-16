#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
} Student;

// Function to update structure fields via pointer
void updateStudent(Student *s, int newId, const char *newName) {
    s->id = newId;
    snprintf(s->name, sizeof(s->name), "%s", newName);
}

int main() {
    // Dynamically allocate a Student structure
    Student *stu = (Student *)malloc(sizeof(Student));
    if (!stu) return 1;

    stu->id = 1;
    snprintf(stu->name, sizeof(stu->name), "Alice");

    printf("Before update: id = %d, name = %s\n", stu->id, stu->name);

    updateStudent(stu, 2, "Bob");  // Pass pointer to structure

    printf("After update: id = %d, name = %s\n", stu->id, stu->name);

    free(stu);  // Free dynamically allocated memory
    return 0;
}
