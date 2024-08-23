#include<stdio.h>
int main(){
    int a, b, choice, c;
    printf("Enter two number");
    scanf("%d%d", &a, &b);
    printf("Enter your choice");
    scanf("%d", &choice);
    switch (choice)
    {   case 1:
        c=a+b;
        printf("%d", c);
        break; }
    { case 2:
        c=a-b;
        printf("%d", c);
        break; }
    { case 3:
        c=a*b;
        printf("%d", c);
        break; }
    default:
        printf("Invalid input");
    return 0;
}
