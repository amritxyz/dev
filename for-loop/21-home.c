#include<stdio.h>
int main(){
	int i, j, k;
    const char n='*';
	for (i=1; i<=5; i++){
        for (k=1; k<=i; k++){
		    for (j=1; j<=k; j++){
			    printf("%c", n);
		    }
        }
		//a=j;
		printf("\n");
		//printf("%d", a);
	}
	return 0;
}

