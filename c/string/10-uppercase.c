#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];

    printf("Enter a line of text: ");
    fgets(str, sizeof(str), stdin);

    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper(str[i]);
        i++;
    }

    printf("Uppercase text: %s\n", str);

    return 0;
}
