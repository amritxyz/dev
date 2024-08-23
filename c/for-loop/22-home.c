#include"stdio.h"
int main(){
	int i, j, a=5;
	for (i=1; i<=a; i++){
		for (j=1; j<=a; j++){
			if(j<=a-i){
				printf(" ");
			}
			else{
				printf("*");
			}
		}
	}
	return 0;
}

