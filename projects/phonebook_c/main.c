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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
	char name[50];
	char phone_number[15];
};

/* Prototypes */
static void	add_contact(FILE *);
static void	display_contacts(FILE *);
static int	display_menu(void);
static void	handle_choice(int , FILE *);

/* add a new contact to the phonebook file */
static void
add_contact(FILE *file)
{
	struct Contact new_contact;

	printf("\nEnter Name: ");
	fflush(stdout);
	getchar();  /* To consume the leftover newline character from previous input */
	fgets(new_contact.name, sizeof(new_contact.name), stdin);
	new_contact.name[strcspn(new_contact.name, "\n")] = 0;  /* Remove newline at the end */

	printf("Enter Phone Number: ");
	fflush(stdout);
	fgets(new_contact.phone_number, sizeof(new_contact.phone_number), stdin);
	new_contact.phone_number[strcspn(new_contact.phone_number, "\n")] = 0;  /* Remove newline */

	/*error handling while writing to file*/
	if (fprintf(file, "%s,%s\n", new_contact.name, new_contact.phone_number) < 0) {
		printf("Error writing to file.\n");
		exit(1);
	}

	printf("\nContact added successfully!\n");
}

/* display all contacts in the phonebook file */
static void
display_contacts(FILE *file)
{
	char name[50], phone_number[15];

	rewind(file);  /* Go to the beginning of the file to read the contacts */

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\nPhonebook:\n");
	while (fscanf(file, "%49[^,],%14[^\n]\n", name, phone_number) == 2) {
		printf("\nName: %s\n", name);
		printf("Phone Number: %s\n", phone_number);
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

/* display the menu and get the user's choice */
static int
display_menu()
{
	int choice;
	printf("\nPhonebook Menu:\n");
	printf("1. Add a new contact\n");
	printf("2. Display all contacts\n");
	printf("3. Exit\n");
	printf("Enter your choice: ");
	fflush(stdout);
	scanf("%d", &choice);
	return choice;
}

/* handle the user's choice */
static void
handle_choice(int choice, FILE *file)
{
	switch (choice) {
		case 1:
			add_contact(file);
			break;
		case 2:
			display_contacts(file);
			break;
		case 3:
			fclose(file);  /* Close the file before exiting */
			printf("Exiting program.\n");
			exit(0);
		default:
			printf("Invalid choice. Please try again.\n");
			exit(1);
	}
}

int
main()
{
	/* Open the file in read/write mode, create if it doesn't exist */
	FILE *file = fopen("phonebook.dat", "a+b");
	if (file == NULL) {
		printf("Error opening file.\n");
		return 1;
	}

	int choice;
	while (1) {
		choice = display_menu(); /* Display the menu and get the choice */
		handle_choice(choice, file); /* Handle the chosen option */
	}

	return 0;
}
