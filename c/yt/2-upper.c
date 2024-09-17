#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void){
	char s[20];
	printf("Enter any words: ");
	fgets(s, sizeof(s), stdin);
	printf("Result :");
	int len=strlen(s);
	/* printf("%d", len); */
	for (int i=0; i<strlen(s); i++){
		if (islower(s[i]))
			printf("%c", s[1] - 32);
		else
			printf("%c", s[i]);
	}
}

