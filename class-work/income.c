#include"stdio.j"
int main(){
	int income, tax = 0;
	printf("Enter income\n");
	scanf("%d", &income);
	if (income<250000){
		tax = 0;
	}
	if (income>250000 && income<500000){
		tax = 0.05 * (income - 250000)
	}
		if (income>500000 && income<1000000){
		tax = 0.05 * (income - 250000) + 0.2 * (income - 500000);
	}

	return 0;
}

