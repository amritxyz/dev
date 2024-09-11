#include<stdio.h>
#include<string.h>
int main(){
    char a[20], b[20];
    int i=0;
    printf("Enter the string: ");
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = 0;
    strcpy(b,a);
    printf("The copy of the array: %s\n", b);
    return 0;
}

