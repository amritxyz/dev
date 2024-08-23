#include<stdio.h>
int main(){
    float a, b;
    char ch[10];
    printf("Enter your choice");
    scanf("%c", &ch);
    printf("Enter a number");
    scanf("%f", &a);
    printf("Enter a number");
    scanf("%f", &b);
    switch (ch)
    { case'+':
        printf("%d", a+b);
        break;
     case'-':
        printf("%d", a-b);
        break;
     case'*':
        printf("%d", a*b);
        break;
     case'/':
        printf("%d", a/b);
        break;
    default:
        printf("Invalid input");}
    return 0;
}
