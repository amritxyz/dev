/*
 * Copyright (C) 2024 Nyx Void
 * https://nyx-void.github.io
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

/* prototypes */
static void sum(float, float);
static void sub(float, float);
static void mul(float, float);
static void dev(float, float);

/* SUM */
static
void sum(float a, float b)
{
	printf("%.2f", a+b);
}

/* SUB */
static
void sub(float a, float b)
{
	printf("%.2f", a-b);
}

/* MUL */
static
void mul(float a, float b)
{
	printf("%.2f", a*b);
}

/* DEV */
static
void dev(float a, float b)
{
	if (b!=0){
		printf("%.2f", a/b);
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

	/* Get numbers from users */
	float a, b;
	printf("Enter first number: ");
	fflush(stdout);
	scanf("%f", &a);
	printf("Enter second number: ");
	fflush(stdout);
	scanf("%f", &b);

	/* Switch case */
	switch (choice) {
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
