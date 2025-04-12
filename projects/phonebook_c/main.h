#ifndef MAIN_H
#define MAIN_H

struct Contact {
    char *name;
    char *phone_number;
};

void add_contact(FILE *);
void display_contacts(FILE *);
int display_menu(void);
void handle_choice(int , FILE *);

#endif /* MAIN_H */
