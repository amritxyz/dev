#include<stdio.h>
int main(){
	FILE *ptr;
	ptr = fopen("Amrit", "r");
	int num;
	fscanf(ptr,"%d", &num);
	printf("The value of num is %d\n", num);
	fclose(ptr);
	return 0;
}

