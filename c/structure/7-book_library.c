#include <stdio.h>
#include <string.h>

/* store book information */
struct Book {
    int id;
    char title[50];
    char author[50];
    int year;
};

int main() {
    struct Book books[5];

    /* data for 5 books */
    for (int i = 0; i < 5; i++) {
        printf("Enter id, title, author, and year for book %d:\n", i + 1);
        scanf("%d %s %s %d", &books[i].id, books[i].title, books[i].author, &books[i].year);
    }

    /* Display book info */
    printf("Book Information:\n");
    for (int i = 0; i < 5; i++) {
        printf("ID: %d, Title: %s, Author: %s, Year: %d\n", books[i].id, books[i].title, books[i].author, books[i].year);
    }

    return 0;
}

