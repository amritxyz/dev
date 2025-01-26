#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

struct node *add(struct node *, int);

struct node
*add(struct node *head, int d)
{
	struct node *ptr = malloc(sizeof(struct node));
	ptr->data = d;
	ptr->link = NULL;

	ptr->link = head;
	head = ptr;
	return head;
}

int main()
{
	struct node *head = malloc(sizeof(struct node));
	head->data = 12;
	head->link = NULL;

	struct node *ptr = malloc(sizeof(struct node));
	ptr->data = 20;
	ptr->link = NULL;

	head->link = ptr;

	int data = 9;

	head = add(head, data);
	ptr = head;

	while (ptr != NULL) {
		printf("%d\n", ptr->data);
		ptr = ptr->link;
	}

	return 0;
}
