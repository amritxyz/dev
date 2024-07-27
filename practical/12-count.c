#include"stdio.h"
int countdigits(int num){
	int count=0;
	while(num!=0){
		num/=10;
		count++;
	}
	return count;
	int main(){
		int n, count;
		printf("Enter a integer: ");
		scanf("%d", n);
		count=countdigits(num);
		printf("Number of digits :%d\n", count);
		return 0;
	}
}

