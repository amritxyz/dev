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

    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter the student's ID: ");
        scanf("%d", &s1[i].id);
        printf("Enter the student's name: ");
        scanf("%s", s1[i].name);
        printf("Enter the student's address: ");
        scanf("%s", s1[i].add);
        /* scanf(" %[^\n]s", s1[i].add); */

        // Input marks for subjects
        for (j = 0; j < NUM_SUBJECTS; j++) {
            printf("Enter mark for subject %d: ", j + 1);
            scanf("%f", &s1[i].M1.subjects[j]);
        }
    }

    printf("\nStudent ID\tName\t\tAddress\t\t");
    printf("Total\t\tAverage\t\tPosition\n");
    for (i = 0; i < NUM_STUDENTS; i++) {
        total = 0;
        for (j = 0; j < NUM_SUBJECTS; j++) {
            total += s1[i].M1.subjects[j];
        }
        average = total / NUM_SUBJECTS;

        printf("%d\t\t%s\t\t%s\t\t", s1[i].id, s1[i].name, s1[i].add);
        printf("%.2f\t\t%.2f\t\t", total, average);

        if (average > 80) {
            printf("Topper\n");
        } else if (average > 60) {
            printf("1st Division\n");
        } else {
            printf("Failed\n");
        }
    }

    return 0;
}

