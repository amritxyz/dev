#include"stdio.h"
int main(){
    int a=1, b, i;
    printf("%d", a);
    for(i=1; i<=5; i++){
        b=a*10+1;
        a=b;
        printf("\t%d", b);
    }
    printf("\n");
    return 0;
}
