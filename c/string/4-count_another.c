#include<stdio.h>
#include<string.h>
int main(){
	char a[20];
	int i=0;
	printf("Enter your name: ");
	fgets(a, sizeof(a), stdin);

	printf("Total chars: %d", strlen(a));
	return 0;
}

