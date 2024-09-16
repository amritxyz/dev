// WAP cteate 5 students record id, name, address, five subjects marks, find the total and average only those records are displays if avg>80 >> toper; 80>avg>60 >> 1st division otherwise fail
// WAP create a

#include<stdio.h>

struct marks{
	float m1, m2, m3, m4, m5;
};

struct students{
	int id;
	char name[20];
	struct marks M1;
	char add[20];
};

int main(){
	int i;
	float total, average;
	struct students s1[100];
	for (i=0; i<5; i++){
		printf("Enter the students id: ");
		fflush(stdout);
		scanf("%d", &s1[i].id);
		printf("Enter the students name: ");
		fflush(stdout);
		scanf("%s", &s1[i].name);
		printf("Enter students address: ");
		fflush(stdout);
		scanf("%s", &s1[i].add);
	//}
	for (i=0; i<5; i++){
		printf("sub no. %d: ", i+1);
		fflush(stdout);
		scanf("%f", &s1[i].M1.m1, &s1[i].M1.m2, &s1[i].M1.m3, &s1[i].M1.m4, &s1[i].M1.m5);
	}
	}
	/* for (i=0; i<5; i++){ */
	/* 	total = s1[i].M1.m1 + s1[i].M1.m2 + s1[i].M1.m3 + s1[i].M1.m4 + s1[i].M1.m5; */
	/* 	average = total/5.0; */
	/* } */
	for (i=0; i<5; i++){
		total = s1[i].M1.m1 + s1[i].M1.m2 + s1[i].M1.m3 + s1[i].M1.m4 + s1[i].M1.m5;
		average = total/5.0;
		printf("Your Id: %d\nYour Name: %s\nYour Address: %s\n", s1[i].id, s1[i].name, s1[i].add );
		if (average > 60 && average < 80) {
			printf("Total: %.2f\nAverage: %.2f\n", total, average);
			printf("Position: 1st division\n");
		} else if (average > 80) {
			printf("Total: %.2f\nAverage: %.2f\n", total, average);
			printf("Position: Topper\n");
		} else {
			printf("Total: %.2f\nAverage: %.2f\n", total, average);
			printf("Position: Failed\n");
		}
	}
	return 0;
}

