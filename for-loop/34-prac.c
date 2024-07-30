#include"stdio.h"
int main(){
	int i, j, k;
	const char n='*';
	for (i=1; i<=5; i++){
		for (k=1; k<=i; k++){
			printf(" ");
		}
			for (j=i; j<=5; j++){
				printf("%c", n);
		}
		printf("\n");
	}
}

