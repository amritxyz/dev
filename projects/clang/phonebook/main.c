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

#include "main.h"

/* Add a new contact to the phonebook file */
void add_contact(FILE *file) {
    struct Contact new_contact;
    char temp_name[50], temp_phone[15];

    printf("\nEnter Name: ");
    fflush(stdout);
    getchar();  /* To consume the leftover newline character from previous input */
    if (fgets(temp_name, sizeof(temp_name), stdin) == NULL) {
        printf("Error reading name.\n");
        return;
    }
    temp_name[strcspn(temp_name, "\n")] = 0;  /* Remove newline at the end */

    printf("Enter Phone Number: ");
    fflush(stdout);
    if (fgets(temp_phone, sizeof(temp_phone), stdin) == NULL) {
        printf("Error reading phone number.\n");
        return;
    }
    temp_phone[strcspn(temp_phone, "\n")] = 0;  /* Remove newline */

    /* Allocate memory dynamically for the name and phone number */
    new_contact.name = malloc(strlen(temp_name) + 1);
    new_contact.phone_number = malloc(strlen(temp_phone) + 1);

    if (!new_contact.name || !new_contact.phone_number) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(new_contact.name, temp_name);
    strcpy(new_contact.phone_number, temp_phone);

    /* Error handling while writing to the file */
    if (fprintf(file, "%s,%s\n", new_contact.name, new_contact.phone_number) < 0) {
        printf("Error writing to file.\n");
        free(new_contact.name);
        free(new_contact.phone_number);
        exit(1);
    }

    printf("\nContact added successfully!\n");

    /* Free allocated memory */
    free(new_contact.name);
    free(new_contact.phone_number);
}

/* Display all contacts in the phonebook file */
void display_contacts(FILE *file) {
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

/* Display the menu and get the user's choice */
int display_menu(void) {
    int choice;
    printf("\nPhonebook Menu:\n");
    printf("1. Add a new contact\n");
    printf("2. Display all contacts\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    fflush(stdout);
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        exit(1);
    }
    return choice;
}

/* Handle the user's choice */
void handle_choice(int choice, FILE *file) {
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
            break;  /* Prevents termination on invalid input */
    }
}

int main() {
    /* Open the file in read/write mode, create if it doesn't exist */
    FILE *file = fopen("phonebook.dat", "a+b");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int choice;
    while (1) {
        choice = display_menu();  /* Display the menu and get the choice */
        handle_choice(choice, file);  /* Handle the chosen option */
    }

    return 0;
}
