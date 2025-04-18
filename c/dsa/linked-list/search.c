// INFO: Traversing With Search Feature In Linked_List #DSA

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *link;
};

static void traverse(struct Node *, int);

	static void
traverse(struct Node *head, int search)
{
	struct Node *current = head;
	int not_found = 0;
	while (current != NULL) {
		if (current->data == search) {
			printf("Data found:\nNode[%d]: %d\n", current->link, search);
			not_found = 1;
		}
		current = current->link;
	}
	if (!(not_found))
		printf("Data not found.\n");
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

	int search;
	printf("Which number you want to search: ");
	scanf("%d", &search);

	traverse(head, search);

	free(head);
	free(ptr);
	return 0;
}
