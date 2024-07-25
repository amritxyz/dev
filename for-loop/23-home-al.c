#include"stdio.h"
int main(){
	int a=5, i, j, k;
	for (i=1; i<=a; i++){
		for (j=i; j<=a; j++){
			printf(" ");
		}
		for(k=1; k<=i; k++ ){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

