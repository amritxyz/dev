/* WAP to convert Celsius to Fahrenheit */
#include"stdio.h"

float c2f(float c){
	return ((9*c)/5)+32;
}

int main(){
	float c;

	printf("Enter celsius: ");
	scanf("%f", &c);
	printf("F = %.2f\n", c2f(c));

	return 0;
}

