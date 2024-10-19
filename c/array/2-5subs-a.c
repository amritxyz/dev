#include <stdio.h>
int main() {
	int marks[5];
	int total = 0;
	float avg;

	printf("Enter marks for 5 subjects:\n");
	scanf("%d%d%d%d%d", &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]);

	total = marks[0] + marks[1] + marks[2] + marks[3] + marks[4];
	avg = (float)total / 5.0;

	printf("Total marks: %d\n", total);
	printf("Average marks: %.2f\n", avg);

	if (avg >= 80) {
		printf("Topper\n");
	} else if (avg >= 60) {
		printf("First division\n");
	} else if (avg >= 50) {
		printf("Second division\n");
	} else {
		printf("Fail\n");
	}

	return 0;
}

