#include<stdio.h>
#include<string.h>

int main(void){
	char names[3][50] = {"Amrit", "Anupam", "ams"};
	char numbers[3][50] = {"9867244404", "9808200850", "9812345678"};

	char name[50];
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = '\0';

	/* char name = scanf("%s", &name); */
	for(int i=0; i<3; i++){
		if (strcmp(names[i], name) == 0){
			printf("Found\n");
			printf("Number: %s\n", numbers[i]);
			return 0;
		}
	}
	printf("Not found\n");
	return 1;
}

