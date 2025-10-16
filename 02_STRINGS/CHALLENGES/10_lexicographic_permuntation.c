#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to swap two characters
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Function to compare characters for qsort
int cmp(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

// Recursive function to generate permutations
void permute(char *str, int l, int r) {
    if (l == r) {
        printf("%s\n", str);
        return;
    }

    for (int i = l; i <= r; i++) {
        // To avoid duplicates in lexicographic order
        int duplicate = 0;
        for (int j = l; j < i; j++) {
            if (str[j] == str[i]) {
                duplicate = 1;
                break;
            }
        }
        if (duplicate) continue;

        swap(&str[l], &str[i]);
        permute(str, l + 1, r);
        swap(&str[l], &str[i]); // backtrack
    }
}

int main() {
    char str[] = "abc";
    int n = strlen(str);

    // Sort the string to start with lexicographic order
    qsort(str, n, sizeof(char), cmp);

    printf("All permutations in lexicographic order:\n");
    permute(str, 0, n - 1);

    return 0;
}
