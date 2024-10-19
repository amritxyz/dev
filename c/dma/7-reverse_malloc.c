/* WAP to reverse a word(string) using malloc */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char *str) {
	int length = strlen(str);
	char *reversed = (char *)malloc((length + 1) * sizeof(char)); // +1 for null terminator
	if (reversed == NULL) {
		printf("Memory allocation failed.\n");
		return;
	}

	for (int i = 0; i < length; i++) {
		reversed[i] = str[length - i - 1];
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

