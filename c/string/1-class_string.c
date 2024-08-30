#include<stdio.h>
#include<string.h>
int main(){
	char a[10];
	printf("Enter your name: ");
	fgets(a, sizeof(a), stdin);
	a[strcspn(a, "\n")]=0;
	puts(a);
	return 0;
}

