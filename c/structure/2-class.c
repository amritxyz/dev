#include<stdio.h>

struct dob {
	int dd, mm, yy;
};

struct records {
	int id; char name[30]; float salary; char address[30];
	struct dob d1;
};

int main(){
	struct records s1;
	printf("Enter Id: ");
	scanf("%d", &s1.id);
	printf("Enter Name: ");
	scanf("%s", &s1.name);
	printf("Enter Salary: ");
	scanf("%f", &s1.salary);
	printf("Enter Address: ");
	scanf("%f", &s1.address);
	printf("Enter DOB: ");
	scanf("%f", &s1.dob);

