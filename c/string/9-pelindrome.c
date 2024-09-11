#include <stdio.h>
#include <string.h>

int main() {
    int i, len;
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    int a = 0; // starting index
    int b = len - 1; // ending index

    int is_palindrome = 1;

    while (a < b) {
        if (str[a] != str[b]) {
            is_palindrome = 0;
            break;
        }
        a++;
        b--;
    }

    if (is_palindrome) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}
