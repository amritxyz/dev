#include<stdio.h>

// prototypes
void sum(float a, float b);
void sub(float a, float b);
void mul(float a, float b);
void dev(float a, float b);

// function declaration

/* SUM */
void sum(float a, float b){
	printf("%.2f", a+b);
}

/* SUB */
void sub(float a, float b){
	printf("%.2f", a-b);
}

/* MUL */
void mul(float a, float b){
	printf("%.2f", a*b);
}

/* DEV */
void dev(float a, float b){
	if (b!=0){
		printf("%.2f", a/b);
	}
	else {
		printf("Error: Division by zero is not allowed.\n");

}
}

/* Main Function */
int main(){
	/*...............*/
	int choice;
	printf("1) SUM\n");
	printf("2) SUB\n");
	printf("3) MUL\n");
	printf("4) DEV\n");
	printf("Enter your choice (1/2/3/4) : ");
	fflush(stdout);
	scanf("%d", &choice);

	/* Get numbers from users */
	float a, b;
	printf("Enter first number: ");
	fflush(stdout);
	scanf("%f", &a);
	printf("Enter second number: ");
	fflush(stdout);
	scanf("%f", &b);

	/* Switch case */
	switch (choice){
		case 1:
			sum(a, b);
			break;
		case 2:
			sub(a, b);
			break;
		case 3:
			mul(a, b);
			break;
		case 4:
			dev(a, b);
			break;
		default:
			printf("Invalid choice!\n");
			break;
	}

	/* Next line */
	printf("\n");
	return 0;
}

