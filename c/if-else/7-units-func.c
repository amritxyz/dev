#include <stdio.h>

#define small 80

int calculate_units(int units)
{
	int bill_amt;
	if (units <= 20) {
		bill_amt = small;
		bill_amt += bill_amt * 0.15;
	}
	else if (units <= 100) {
		bill_amt = small;
		bill_amt += (units - 20) * 8.0;
		bill_amt += bill_amt * 0.15;
	}
	else if (units <= 200) {
		bill_amt = small;
		bill_amt += (units - 20) * 4.0;
		bill_amt += (units - 100) * 10.0;
		bill_amt += bill_amt * 0.15;
	}
	else {
		bill_amt = 20 * 4.0;
		bill_amt += (units - 20) * 4.0;
		bill_amt += (units - 100) * 10.0;
		bill_amt += units * 12.0;
		bill_amt += bill_amt * 0.15;
	}
}
int main()
{
	int units;
	float bill_amt;
	printf("Enter the units consumed: ");
	fflush(stdout);
	scanf("%d", &units);

	bill_amt = calculate_units(units);

	printf("Total rs: %f\n", bill_amt);

	return 0;
}

