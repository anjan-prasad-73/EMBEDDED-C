#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function 1: Reverse string
void reverseString(char *str) {
    int len = strlen(str);
    for(int i=0; i<len/2; i++) {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}

// Function 2: Convert to uppercase
void toUpperCase(char *str) {
    for(int i=0; str[i]; i++)
        str[i] = toupper(str[i]);
}

// Function 3: Count vowels
void countVowels(char *str) {
    int count = 0;
    for(int i=0; str[i]; i++) {
        char c = tolower(str[i]);
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') count++;
    }
    printf("Number of vowels: %d\n", count);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove newline

    void (*strFuncs[])(char*) = {reverseString, toUpperCase, countVowels};

    printf("Choose operation: 0-Reverse, 1-ToUpper, 2-CountVowels: ");
    int choice;
    scanf("%d", &choice);

    if(choice >=0 && choice <=2) {
        strFuncs[choice](str);
        if(choice != 2) printf("Result: %s\n", str);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
