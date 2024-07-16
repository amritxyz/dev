#include"stdio.h"
int main(){
	char grade;
	int marks;
	printf("Enter your marks: ");
	scanf("%d", &marks);
	if(marks<=100 && marks>=90){
		grade = 'A';
	}
	else if(marks<=89 &&  marks>=80){
		grade='B';
	}
	else if(marks<=79 && marks>=70){
		grade='C';
	}
	else if(marks<=69 && marks>=60){
		grade='D';
	}
	else if(marks<=59 && marks>=50){
		grade='E';
	}
	else if(marks<=49 && marks>=40){
		grade='F';
	}
	else{
		grade='G';
	}
	return 0;
}

