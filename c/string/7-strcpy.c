#include<stdio.h>
#include<string.h>
int main(){
    char a[20], b[20], c[20];
    int i=0;
    printf("Enter the string: ");
    fgets(a, sizeof(a), stdin);
    printf("Enter the string: ");
    fgets(b, sizeof(b), stdin);
    //a[strcspn(a, "\n")] = 0; // remove the newline character
    strcpy(c,a);
    strcpy(c,b);
    printf("The copy of the array: %s", c);
    return 0;
}

