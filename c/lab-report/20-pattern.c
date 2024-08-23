#include"stdio.h"
int main(){
	int a=5, i, j, k;
	for (i=5; i>=1; i--){
		for (j=i; j<a; j++){
			printf(" ");
		}
		for(k=1; k<=1; k++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

