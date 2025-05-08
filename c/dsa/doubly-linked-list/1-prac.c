#include <stdio.h>
#include <stdlib.h>

struct Node {
	void *data;
	struct Node *link;
	struct Node *prev;
};

static void
add_node_at_position(void *data, struct Node *head, int position)
{
	struct Node *current = head;
	int i = 0;

	while (i < position && current->link != head) {
		current = current->link;
		i++;
	}

	struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
	new_node->data = data;

	new_node->link = current;
	new_node->prev = current->prev;

	current->prev->link = new_node;
	current->prev = new_node;

	// If inserting at head position, swap data
	if (position == 0) {
		void *tmp = head->data;
		head->data = new_node->data;
		new_node->data = tmp;
	}

	// Print the list (circular traversal)
	current = head;
	i = 0;
	do {
		printf("Node[%d] -> data [%d], link [%p], prev [%p]\n", 
				i, *(int *)current->data, 
				(void *)current->link, 
				(void *)current->prev);
		current = current->link;
		i++;
	} while (current != head);
}

int main(int argc, char *argv[])
{
	int position;
	if (argc == 2) {
		position = atoi(argv[1]);
		if (position < 0) {
			fprintf(stderr, "Invalid position: must be >= 0\n");
			return EXIT_FAILURE;
		}
	} else {
		fprintf(stderr, "Usage: %s <node_position>\n", argv[0]);
		return EXIT_FAILURE;
	}

	// Create node 0
	struct Node *ptr_0 = (struct Node *) malloc(sizeof(struct Node));
	int *data_0 = (int *) malloc(sizeof(int));
	*data_0 = 1;
	ptr_0->data = data_0;

	// Create node 1
	struct Node *ptr_1 = (struct Node *) malloc(sizeof(struct Node));
	int *data_1 = (int *) malloc(sizeof(int));
	*data_1 = 2;
	ptr_1->data = data_1;

	// Create node 2
	struct Node *ptr_2 = (struct Node *) malloc(sizeof(struct Node));
	int *data_2 = (int *) malloc(sizeof(int));
	*data_2 = 3;
	ptr_2->data = data_2;

	// Link the nodes (circular doubly linked list)
	ptr_0->link = ptr_1; ptr_0->prev = ptr_2;
	ptr_1->link = ptr_2; ptr_1->prev = ptr_0;
	ptr_2->link = ptr_0; ptr_2->prev = ptr_1;

	// New data to insert
	int *data_3 = (int *) malloc(sizeof(int));
	*data_3 = 4;

	add_node_at_position(data_3, ptr_0, position);

	return EXIT_SUCCESS;
}
