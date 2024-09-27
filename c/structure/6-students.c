#include <stdio.h>
#include <string.h>

#define NUM_STUDENTS 2
#define NUM_SUBJECTS 3

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
        /* scanf(" %[^\n]%*c", s1[i].add); */

        for (j = 0; j < NUM_SUBJECTS; j++) {
            printf("Enter mark for subject %d: ", j + 1);
	    fflush(stdout);
            scanf("%f", &s1[i].M1.subjects[j]);
        }
    }

    printf("\nStudent ID\tName\t\tAddress\t\tTotal\t\tAverage\t\tPosition\n");
    for (i = 0; i < NUM_STUDENTS; i++) {
        /* Check if address is "Butwal" */
        if (strcasecmp(s1[i].add, "Butwal") == 0) {
            total = 0;
            for (j = 0; j < NUM_SUBJECTS; j++) {
                total += s1[i].M1.subjects[j];
            }
            average = total / NUM_SUBJECTS;

            printf("%d\t\t%s\t\t%s\t\t%.2f\t\t%.2f\t\t", s1[i].id, s1[i].name, s1[i].add, total, average);

            if (average > 80) {
                printf("Topper\n");
            } else if (average > 60) {
                printf("1st Division\n");
            } else {
                printf("Failed\n");
            }
        }
    }

    return 0;
}

