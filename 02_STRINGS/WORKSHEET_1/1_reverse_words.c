#include <stdio.h>

int main() {
    char str[] = "hello world from C";
    int start, end, i, j;
    char words[50][50];
    int wordCount = 0, k = 0;

    // Split words manually
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] != ' '){
            words[wordCount][k++] = str[i];
        } else {
            words[wordCount][k] = '\0';
            wordCount++;
            k = 0;
        }
    }
    words[wordCount][k] = '\0';
    wordCount++;

    // Print words in reverse order
    for(i = wordCount-1; i >= 0; i--){
        j = 0;
        while(words[i][j] != '\0') printf("%c", words[i][j++]);
        if(i != 0) printf(" ");
    }
    return 0;
}
