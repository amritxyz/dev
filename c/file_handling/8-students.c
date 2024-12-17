#include <stdio.h>

#define NUM_STUDENTS 2
#define NUM_SUBJECTS 5

struct marks {
	float subjects[NUM_SUBJECTS];
};

struct students {
	int id;
	char name[20];
	struct marks M1;
	char add[50];
};

int main() {
	int i, j;
	float total, average;
	struct students s1[NUM_STUDENTS];

	FILE *file = fopen("school.txt", "w");
	if (file == NULL) {
		printf("Error opening file!\n");
		return 1;
	}

	for (i = 0; i < NUM_STUDENTS; i++) {
		printf("Enter the student's ID: ");
		fflush(stdout);
		scanf("%d", &s1[i].id);
		printf("Enter the student's name: ");
		fflush(stdout);
		scanf("%s", s1[i].name);
		printf("Enter the student's address: ");
		fflush(stdout);
		scanf("%s", s1[i].add);

	/* subjects */
		for (j = 0; j < NUM_SUBJECTS; j++) {
			printf("Enter mark for subject %d: ", j + 1);
			fflush(stdout);
			scanf("%f", &s1[i].M1.subjects[j]);
		}
	}

	fprintf(file, "\nStudent ID\tName\t\tAddress\t\t");
	fprintf(file, "Total\t\tAverage\t\tPosition\n");

	for (i = 0; i < NUM_STUDENTS; i++) {
		total = 0;
		for (j = 0; j < NUM_SUBJECTS; j++) {
			total += s1[i].M1.subjects[j];
		}
		average = total / NUM_SUBJECTS;

		fprintf(file, "%d\t\t%s\t\t%s\t\t", s1[i].id, s1[i].name, s1[i].add);
		fprintf(file, "%.2f\t\t%.2f\t\t", total, average);

		if (average > 80) {
			fprintf(file, "Topper\n");
		} else if (average > 60) {
			fprintf(file, "1st Division\n");
		} else {
			fprintf(file, "Failed\n");
		}
	}
	fclose(file);
	printf("Data written to school.txt successfully.\n");

	return 0;
}
