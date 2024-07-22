#include"stdio.h"
int main(){
    int i, j;
    for (i=5;i>=1;i--){
         for (j=1;j<=i;j++)
         {
            j=j*10 + 1;
            printf("%d\t", j);
         }
         printf("\n");
    }
    return 0;
}

