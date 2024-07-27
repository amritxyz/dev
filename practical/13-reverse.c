#include"stdio.h"
int main(){
	int n, r, rev=0;
	printf("Enter the number: ");
	scanf("%d", &n);
	while(n>0){
		r=n%10;
		rev=rev*10+r;
		n=n/10;
	}
	printf("The reverse number is %d\n", rev);
	return 0;
}

