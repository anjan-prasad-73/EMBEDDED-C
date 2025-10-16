#include <stdio.h>

void cmd1() { printf("Command 1 executed\n"); }
void cmd2() { printf("Command 2 executed\n"); }
void cmd3() { printf("Command 3 executed\n"); }

int main() {
    void (*cmdTable[])(void) = {cmd1, cmd2, cmd3};

    int choice;
    printf("Enter command number (0-2): ");
    scanf("%d",&choice);

    if(choice>=0 && choice<=2)
        cmdTable[choice](); // Call command via pointer
    else
        printf("Invalid command!\n");

    return 0;
}
