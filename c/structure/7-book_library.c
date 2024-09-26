#include <stdio.h>
#include <string.h>

#define n 2

/* store book information */
struct Book {
    int id;
    char title[50];
    char author[50];
    int year;
};

int main() {
    struct Book books[n];

    /* data for 5 books */
    for (int i = 0; i < n; i++) {
        printf("Enter id, title, author, and year for book %d:\n", i + 1);
        scanf("%d %s %s %d", &books[i].id, books[i].title, books[i].author, &books[i].year);
    }

    /* Display book info */
    printf("Book Information:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Title: %s, Author: %s, Year: %d\n", books[i].id, books[i].title, books[i].author, books[i].year);
    }

    return 0;
}

