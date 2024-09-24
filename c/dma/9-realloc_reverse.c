/* WAP to reverse a word(string) using realloc */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char *str) {
    int length = strlen(str);
    char *reversed = (char *)malloc(sizeof(char)); // Start with minimal allocation
    if (reversed == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < length; i++) {
        reversed = (char *)realloc(reversed, (i + 2) * sizeof(char)); // Resize for new character
        if (reversed == NULL) {
            printf("Reallocation failed.\n");
            return;
        }
        reversed[i] = str[length - i - 1]; // Reverse the string
    }
    reversed[length] = '\0'; // Null-terminate the string

    printf("Reversed string: %s\n", reversed);
    free(reversed);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%99s", str); // Limit input to prevent overflow

    reverseString(str);
    return 0;
}

