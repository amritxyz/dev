#include"stdio.h"
int main(){
    int a=1, b, i;
    printf("\n%d\n", a);
    for(i=1; i<=5; i++){
        b=a*10+1;
        a=b;
        printf("%d\n", b);
    }
    printf("\n");
    return 0;
}
