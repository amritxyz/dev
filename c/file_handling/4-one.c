#include<stdio.h>

int main() {
	FILE *ptr;
	int num;
	ptr = fopen("Amrit", "r");
	if(ptr == NULL) {
		fprintf(stderr, "Sorry the file doesn't exists!\n");
		return 1;
	}
	else {
		fscanf(ptr,"%d", &num);
		printf("The value of num is %d\n", num);
		fclose(ptr);
		return 0;
	}
}

