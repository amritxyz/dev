#include"stdio.h"
int main(){
	int i, j;
	const char n='*';
	for (i=1; i<=5; i++){
		for (j=i; j<=5; j++){
			printf("%c", n);
		}
		printf("\n");
	}
}

