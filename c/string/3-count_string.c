#include<stdio.h>
#include<string.h>
int main(){
	char a[20];
	int i=0;
	printf("Enter a word: ");
	fgets(a, sizeof(a), stdin);  // Correct usage of fgets
	a[strcspn(a, "\n")]=0; // Remove "Newline" >> "/n" Which "fgets" always includes
	while(a[i]!='\0')
		i++;
	printf("Total chars: %d\n", i);
	return 0;
}

