/*
 * Copyright (C) 2024 Nyx Void
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * You can find the full text of the GNU General Public License at:
 * https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html
 */

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
