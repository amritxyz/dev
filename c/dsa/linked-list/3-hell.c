#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *link;
};

static void traverse(struct Node *);

static void
traverse(struct Node *head)
{
	struct Node *current = head;
	while (current != NULL) {
		printf("Node[%d] = %d\n", current, current->data);
		current = current->link;
	}
	printf("NULL\n");
}

int main(void)
{
	// First Node
	struct Node *head = (struct Node*) malloc(sizeof(struct Node));
	head->data = 1;
	// head->link = NULL;

	// Second Node
	struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
	head->link = ptr;
	ptr->data = 2;

	ptr->link = NULL;

	traverse(head);

	free(head);
	free(ptr);
	return 0;
}
