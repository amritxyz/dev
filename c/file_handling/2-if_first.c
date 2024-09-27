#include<stdio.h>

int main() {
	FILE *ptr;
	ptr = fopen("Amrit", "r");
	char c[50];
	if(ptr == NULL) {
		fprintf(stderr, "Sorry the file doesn't exists!\n");
		return 1;
	}
	else {
		fscanf(ptr,"%s", &c);
		printf("1st word is: %s\n", c);
		fclose(ptr);
		return 0;
	}
}

