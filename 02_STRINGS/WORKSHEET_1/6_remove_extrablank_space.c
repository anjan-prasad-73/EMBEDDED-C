#include <stdio.h>

int main() {
    char str[] = " ANJAN  PRASAD ";
    char result[100];
    int i = 0, k = 0;

    // Skip leading spaces
    while(str[i] == ' ') i++;

    for(; str[i] != '\0'; i++){
        if(str[i] != ' '){
            result[k++] = str[i];
        } else if(result[k-1] != ' '){
            result[k++] = ' ';
        }
    }
    // Remove trailing space
    if(k > 0 && result[k-1] == ' ') k--;
    result[k] = '\0';

    for(i = 0; i < k; i++) printf("%c", result[i]);
}
