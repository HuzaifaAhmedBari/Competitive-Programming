#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Recursive function to concatenate two strings
char *concat(char *dest, char *src, int j, int i) {
    dest = (char *)realloc(dest, (j + 2) * sizeof(char)); // Reallocate memory for the growing string
    dest[j] = src[i]; // Append the current character from src to dest
    if (i == 0) {
        dest[j + 1] = '\0'; // Add null terminator when all characters are copied
        return dest; // Return the concatenated string
    }
    return concat(dest, src, j + 1, i - 1); // Recursive call to copy the next character
}

int main() {
    char str[] = "Hello";
    char src[] = "World";
    int len = strlen(src);
    int len1 = strlen(str);

    // Allocate initial memory for the destination string
    char *result = (char *)malloc((len1 + 1) * sizeof(char));
    strcpy(result, str); // Copy the initial string into the allocated memory

    // Concatenate strings using the recursive function
    result = concat(result, src, len1, len - 1);

    printf("Concatenated String: %s\n", result);

    // Free the allocated memory
    free(result);

    return 0;
}

