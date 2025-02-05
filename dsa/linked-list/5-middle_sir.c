#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *link;
}

int main()
{
	struct Node *head = (struct Node*) malloc(sizeof(struct Node));

	head->data = 1;
	head->link = (struct Node*) malloc(sizeof(struct Node));
	head->link->data = 2;
	head->link->link = (struct Node*) malloc(sizeof(struct Node));
	head->link->link->data = 3;
	head->link->link->link = NULL;

	return 0;
}
