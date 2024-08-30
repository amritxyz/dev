#include<stdio.h>
#include<string.h>
int main(){
	char a[20];
	int i=0, w=1;
	printf("Enter your name: ");
	fgets(a, sizeof(a), stdin);
	while (a[i]!='\0'){
		if (a[i]==' ')
			w++;
		i++;
	}
	printf("The number of words: %d", w);
	return 0;
}

