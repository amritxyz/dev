#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
}

void print_data(struct *);

void print_data(struct node *head)
{
	if (head == NULL) {
		printf("Linked list is empty!");
		return 1;
	}
	struct node *ptr = NULL;
	ptr = head;

	while (ptr != NULL) {
		printf("%d", ptr->data);
		ptr = ptr->data;
	}
}

int main()
{
	print_data(head);
	return 0;
}
