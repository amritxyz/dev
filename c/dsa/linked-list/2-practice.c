// INFO: Traversing In Linked_List #DSA

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
	struct Node *current_node = head;
	while (current_node != NULL) {
		printf("%d -> ", current_node->data);
		current_node = current_node->link;
	}
	printf("NULL\n");
}

int main()
{
	struct Node *head = (struct Node*) malloc(sizeof(struct Node));

	/*Creating Nodes*/
	head->data = 1;
	head->link = (struct Node*) malloc(sizeof(struct Node));
	head->link->data = 2;
	head->link->link = (struct Node*) malloc(sizeof(struct Node));
	head->link->link->data = 3;
	head->link->link->link = NULL;

	/*Traverse Function*/
	printf("LinkedList: ");
	traverse(head);

	struct Node *current_node = head;
	struct Node *next_node;

	while (current_node != NULL) {
		next_node = current_node->link;
		free(current_node);
		current_node = next_node;
	}

	return 0;
}
