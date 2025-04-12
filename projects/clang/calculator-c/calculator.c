/*
 * Copyright (C) 2024 amritxyz
 * https://amritxyz.github.io
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include<stdio.h>
#include <stdlib.h>

#include "calculator.h"

/* SUM */
int
sum(float a, float b)
{
	return a+b;
}

/* SUB */
int
sub(float a, float b)
{
	return a-b;
}

/* MUL */
int
mul(float a, float b)
{
	return a*b;
}

/* DEV */
int
dev(float a, float b)
{
	if (b!=0){
		return a/b;
	} else {
		printf("Error: Division by zero is not allowed.\n");
		exit(1);
	}
}

/* Main Function */
int
main() {
	int choice;
	printf("1) SUM\n");
	printf("2) SUB\n");
	printf("3) MUL\n");
	printf("4) DEV\n");
	printf("Enter your choice (1/2/3/4) : ");
	fflush(stdout);
	scanf("%d", &choice);

	if (choice < 1 || choice > 4) {
		printf("Error: Invalid choice! Please enter a number between 1 and 4.\n");
		exit(1);
	}

	/* Get numbers from users */
	float a, b;
	printf("Enter first number: ");
	fflush(stdout);
	scanf("%f", &a);
	printf("Enter second number: ");
	fflush(stdout);
	scanf("%f", &b);

	float result;
	/* Switch case */
	switch (choice) {
		case 1:
			result = sum(a, b);
			break;
		case 2:
			result = sub(a, b);
			break;
		case 3:
			result = mul(a, b);
			break;
		case 4:
			result = dev(a, b);
			break;
		default:
			printf("Invalid choice!\n");
			exit(1);
	}
	printf("Result = %.2f\n", result);

	return 0;
}
