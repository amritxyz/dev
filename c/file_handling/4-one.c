#include<stdio.h>

int main() {
	FILE *ptr;
	int c[50];
	ptr = fopen("Amrit", "r");
	if(ptr == NULL) {
		fprintf(stderr, "Sorry the file doesn't exists!\n");
		return 1;
	}
	else {
		while(fscanf(ptr, "%s", c)!=EOF){
			printf("%s ", c);
		}
		printf("\n");
	}
	return 0;
}

