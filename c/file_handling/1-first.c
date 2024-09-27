#include<stdio.h>
int main(){
	FILE *ptr;
	ptr = fopen("Amrit", "r");
	char c[50];
	fscanf(ptr,"%s", &c);
	printf("1st word is: %s\n", c);
	fclose(ptr);
	return 0;
}

