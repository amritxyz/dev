// WAP cteate 5 students record id, name, address, five subjects marks, find the total and average only those records are displays
// WAP create a

#include<stdio.h>
struct employee{
	int emp_id;
	char emp_name[20];
	float salary;
	char add[20];
};

int main(){
	struct employee s1;
	printf("Enter the employee id: \n");
	scanf("%d", &s1.emp_id);
	printf("Enter the employee name: \n");
	scanf("%s", &s1.emp_name);
	printf("Enter your salary: \n");
	scanf("%f", &s1.salary);
	printf("Enter your address: \n");
	scanf("%s", &s1.add);
	printf("Your Id: %d\nYour Name: %s\nYour salary: %.2f\nYour Address: %s\n", s1.emp_id, s1.emp_name, s1.salary, s1.add);
}
