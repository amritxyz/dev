#include"stdio.h"
void factorial();
void main(){
	factorial();
}
void factorial(){
	int i, n, a=1;
	printf("Enter a number to get its factorial: ");
	scanf("%d", &n);
	for (i=1; i<=n; i++){
		a*=i;
	}
	printf("%d\n", a);
}

