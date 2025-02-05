#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *link;
};

static void add_last(struct Node *, int);

static void
add_last(struct Node *head, int data)
{
	while (head != NULL) {
		head = head->link;
	}
}

int main()
{
	struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));

	ptr->data = 1;
	ptr->link = (struct Node*) malloc(sizeof(struct Node));
	ptr->link->data = 2;
	ptr->link->link = (struct Node*) malloc(sizeof(struct Node));
	ptr->link->link->data = 3;
	ptr->link->link->link = NULL;

	struct Node *new = (struct Node*) malloc(sizeof(struct Node));

	add_list(ptr, );

	return 0;
}
