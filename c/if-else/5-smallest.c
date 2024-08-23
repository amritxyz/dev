#include"stdio.h"
int main(){
	int a, b, c;
	printf("Enter 3 numbers :");
	scanf("%d%d%d", &a, &b, &c);
	if(a>b && c>b)
	{
		printf("%d is smallest", b);
	}
	else if(b>c && a>c)
	{
		printf("%d is smalles", c);
	}
	else{
		printf("%d is smallest", a);
	}
	return 0;
}

