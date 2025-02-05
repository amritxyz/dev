#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *link;
};

static void	add(struct Node *);
static void	print(struct Node *, int);

static void
add(struct Node *head)
{

}

static void
print(struct Node *head, int data)
{

}

int main()
{
	struct Node *head = (struct Node *) malloc(sizeof(struct Node));
	head->data = 1;
	head->link = NULL;

	struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
	ptr->data = 2;
	ptr->link = NULL;

	head->link = ptr;

	struct Node *current = head;
	struct Node *new;

	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->link;
	}
	printf("NULL\n");

	free(ptr);
	free(head);
	free(current);

	return 0;
}
