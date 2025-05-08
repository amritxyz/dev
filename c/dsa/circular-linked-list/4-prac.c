#include <stdio.h>
#include <stdlib.h>

struct Node {
	void *data;
	struct Node *link;
};

static void
add_node_at_position(void *data, struct Node *head, int position)
{
	struct Node *current = head;
	int i = 0;

	while (i < position - 1 && current->link != head) {
		current = current->link;
		i++;
	}

	struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->link = current->link;
	current->link = new_node;

	/* If inserting at position 0 (head), swap data with new node to maintain head position */
	if (position == 0) {
		void *tmp = head->data;
		head->data = new_node->data;
		new_node->data = tmp;
	}

	current = head;
	i = 0;
	do {
		printf("Node[%d] -> link [%p] = data [%d]", i, (void *)current->link, *(int *)current->data);
		i++;
		printf("\n");
		current = current->link;
	} while (current != head);
}

int main(int argc, char *argv[])
{
	/* Default position = 0 (insert at head) */
	// int position = 0;
	int position;

	/* Use user-provided position if given */
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

	/* Circular Linked-list */
	ptr_2->link = ptr_0;

	int *data_3 = (int *) malloc(sizeof(int));
	*data_3 = 4;

	add_node_at_position(data_3, ptr_0, position);

	return EXIT_SUCCESS;
}
