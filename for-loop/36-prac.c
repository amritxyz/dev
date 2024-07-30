#include"stdio.h"
int main(){
	int i, j, k;
	const char n='*';
	for (i=1; i<=5; i++){
		for (j=1; j<=5-i; j++){
			printf(" ");
		}
		for (k=1; k<=2*i-1; k++){
			printf("%c", n);
		}
		printf("\n");
	}
	return 0;
}

