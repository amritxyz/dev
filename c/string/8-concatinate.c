// Strcmp and strcmpi
#include<stdio.h>
#include<string.h>
int main(){
    char a[10], b[10], c[20];	int i=0, j=0;
    printf("Enter the first string: ");
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = 0;
    printf("Enter the second string: ");
    fgets(b, sizeof(b), stdin);
    b[strcspn(b, "\n")] = 0;
    while (a[i]!='\0'){
	    c[i]=a[i];
	    i++;
    }
    while (b[i]!='\0'){
	    c[i]=b[j];
	    j++;
	    i++;
    }
    c[i]='\0';
	    printf("The string is: %s\n", c);
    //a[strcspn(a, "\n")] = 0; // remove the newline character
    //printf("The addition of the array: %s"), strcpy(b, a);
    return 0;
}

