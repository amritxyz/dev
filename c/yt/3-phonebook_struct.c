#include<stdio.h>
#include<string.h>

typedef struct{
	char names[50];
	char numbers[20];
}person;

int main(void){
	person people[4];
	strcpy(people[0].names, "Amrit");
	strcpy(people[0].numbers, "9867244404");
	strcpy(people[1].names, "Anupam");
	strcpy(people[1].numbers, "9808200850");
	strcpy(people[2].names, "Ams");
	strcpy(people[2].numbers, "9812345678");

	char name[50];
	printf("Name: ");
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = '\0';

	/* char name = scanf("%s", &name); */
	for(int i=0; i<3; i++){
		if (strcmp(people[i].names, name) == 0){
			printf("Found\n");
			printf("Number: %s\n", people[i].numbers);
			return 0;
		}
	}
	printf("Not found\n");
	return 1;
}

