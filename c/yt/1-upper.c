#include<stdio.h>
#include<string.h>
int main(void){
	char str[20];
	printf("Enter any word: ");
	fgets(str, sizeof(str), stdin);
	for(int i=0; i<strlen(str); i++){
		if (str[i] >= 'a' && str[i] <= 'z')
			printf("%c", str[i] - 32);
		else
			printf("%c", str[i]);
	}
}

