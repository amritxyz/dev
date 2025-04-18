// INFO: Traversing In Linked_List #DSA

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *link;
};

static void
traverse(struct Node *head)
{
	struct Node *current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->link;
	}
	printf("NULL\n");
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

	printf("LinkedList: ");
	traverse(head);

	struct Node *current = head;
	struct Node *nextNode;

	while (current != NULL) {
		nextNode = current->link;
		free(current);
		current = nextNode;
	}

	return 0;
}
