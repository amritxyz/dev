#include"stdio.h"
int main(){
    int a=1, i;
    printf("\n%d\n", a);
    for(i=1; i<=5; i++){
        a=a*10+1;
        printf("%d\n", a);
    }
    printf("\n");
    return 0;
}
