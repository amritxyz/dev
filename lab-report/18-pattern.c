#include"stdio.h"
int main(){
    int a=1, b, i;
    printf("%d\n", a);
    for(i=1; i<=4; i++){
        b=a*100+1;
        a=b;
        printf("%d\n", b);
    }
    return 0;
}

