#include<stdio.h>
int main(){
	char a[10];
	int i=0;
	printf("Enter your name: ");
	fgets(a, sizeof(a), stdin);
	while(a[i]!='\0'){
		printf("\n%c", a[i]);
		i++;
	}
	//puts(a);
	return 0;
}

