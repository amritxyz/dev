#include <stdio.h>
#include <stdlib.h>

struct Node {
	void *data;
	struct Node *link;
};

static void
add_first_node(void *data, struct Node *head)
{
	struct Node *current = head;
	current = head;

	while (current->link != head)
		current = current->link;

	struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->link = head;
	current->link = new_node;

	/* WARN: Add node at last
	 * ----------------------------------------------------
	 * struct Node *new_node = malloc(sizeof(struct Node));
	 * new_node->data = data;
	 * new_node->link = head->link;
	 * head->link = new_node; 
	 * ---------------------------------------------------
	 */

	void *tmp = head->data;
	head->data = new_node->data;
	new_node->data = tmp;

	current = head->link;
	int i = 0;
	do {
		/* INFO: %p for specifying pointer */
		printf("Node[%d] -> link [%p] = data [%d]", i, (void *)current->link, *(int *)current->data);
		i++;
		printf("\n");
		current = current->link;
	} while (current != head->link);

	// exit(0);
}

int main(int argc, char *argv[])
{
	struct Node *ptr_0 = (struct Node *) malloc(sizeof(struct Node));
	int *data_0 = (int *) malloc(sizeof(int));
	*data_0 = 1;
	ptr_0->data = data_0;

	struct Node *ptr_1 = (struct Node *) malloc(sizeof(struct Node));
	int *data_1 = (int *) malloc(sizeof(int));
	*data_1 = 2;
	ptr_1->data = data_1;
	ptr_0->link = ptr_1;

	struct Node *ptr_2 = (struct Node *) malloc(sizeof(struct Node));
	int *data_2 = (int *) malloc(sizeof(int));
	*data_2 = 3;
	ptr_2->data = data_2;
	ptr_1->link = ptr_2;

	int *data_3 = (int *) malloc(sizeof(int));
	*data_3 = 4;

	/* Curcular Linked-list */
	ptr_2->link = ptr_0;

	/* Call The function */
	add_first_node(data_3, ptr_0);

	return EXIT_SUCCESS;
}
