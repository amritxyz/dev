#include"stdio.h"
int main(){
	int n, r, rev=0, a;
	printf("Enter the number: ");
	scanf("%d", &n);
	a=n;
	while(n>0){
		r=n%10;
		rev=rev*10+r;
		n=n/10;
	}
	printf("The reverse number is %d\n", rev);
	if (a==rev){
		printf("%d is a palindrome\n", a);
	} else {
		printf("%d is not a palindrome\n", a);
	}
	return 0;
}

