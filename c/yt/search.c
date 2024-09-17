#include<stdio.h>
int main(void){
	int n;
	int number[]={20, 500, 10, 5, 100, 1, 50};
	scanf("%d", &n);
	for(int i=0; i<7; i++){
		if(number[i] == n){
			printf("Found\n");
			return 0;
		}
	} printf("Not found");
	return 1;
}

