/* WAP to count and print The Vowels and Consonants in the user defined word */
#include<stdio.h>
#include<string.h>
int main(){
    char a[50];
    int i=0, v=0, c=0;
    printf("Enter any Words: ");
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = 0; // remove the newline character
    while (a[i]!='\0'){
        if(a[i]==' ') // skip spaces
            i++;
        else if(a[i]=='A' || a[i]=='E' ||a[i]=='I' ||a[i]=='O' ||a[i]=='U' || a[i]=='a' || a[i]=='e' ||a[i]=='i' ||a[i]=='o' ||a[i]=='u')
            v++;
        else
            c++;
        i++;
    }
    printf("The Number of Vowels: %d\nThe Number of Consonants: %d\n", v, c);
    return 0;
}

