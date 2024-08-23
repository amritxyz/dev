#include"stdio.h"
int main(){
	const char n='*';
	int i, j;
	for (i=1; i<=5; i++){
		for(j=i; j>=1; j--){
			printf("%c", n);
		}
		printf("\n");
	}
	return 0;
}

