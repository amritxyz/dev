//WAP enter the n number of subject find the total and average of the marks

#include"stdio.h"
int main() {
	int i = 1, a, m, total;
	printf("Enter the number of subjects: ");
	fflush(stdout);
	scanf("%d", &a);
	do {
		printf("Enter the marks");
		scanf("%d", &m);
		total+=m;
		i++;
	} while (i<=a);
	float avg = total/a;
	printf("The total marks: %d\n", total);
	printf("avg marks: %.2f\n", avg);
	return 0;
}

