#include <stdio.h>

#define NO_OF_CHARS 256

// Function to preprocess the bad character heuristic
void badCharHeuristic(char str[], int size, int badChar[])
{
    int i;
    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badChar[i] = -1;

    // Fill the actual value of last occurrence
    for (i = 0; i < size; i++)
        badChar[(int)str[i]] = i;
}

// Function to get string length manually
int strLength(char str[])
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

// Boyer-Moore search using bad character heuristic
void search(char text[], char pattern[])
{
    int m = strLength(pattern);
    int n = strLength(text);

    int badChar[NO_OF_CHARS];

    // Preprocess the pattern
    badCharHeuristic(pattern, m, badChar);

    int s = 0; // shift of the pattern with respect to text
    while (s <= (n - m))
    {
        int j = m - 1;

        // Keep reducing j while characters of pattern and text match
        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        // If the pattern is present at current shift
        if (j < 0)
        {
            printf("Pattern found at index %d\n", s);
            s += (s + m < n) ? m - badChar[(int)text[s + m]] : 1;
        }
        else
        {
            int shift = j - badChar[(int)text[s + j]];
            s += (shift > 1) ? shift : 1; // ensure at least shift of 1
        }
    }
}

int main()
{
    char text[100], pattern[50];

    printf("Enter text: ");
    gets(text);
    printf("Enter pattern: ");
    gets(pattern);

    search(text, pattern);

    return 0;
}
