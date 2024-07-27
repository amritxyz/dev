#include"stdio.h"
int main(){
	int y;
	printf("Enter any year: ", y);
	scanf("%d", &y);
	if (y<=1000){
		printf("Not a valid date\n");
	} else if (y%400==0 || y%4==0 && y%100!=0){
		printf("Year is leap year\n");
	} else{
		printf("Year is not leap year\n");
	}
	return 0;
}

