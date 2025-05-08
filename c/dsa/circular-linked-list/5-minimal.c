#include <stdio.h>
#include <stdlib.h>

struct Node {
	void *data;
	struct Node *link;
};

int main(void)
{
	int total_nodes = 4;

	struct Node *head = NULL;
	struct Node *tail = NULL;

	for (int i = 1; i <= total_nodes; i++) {
		struct Node *new_node = malloc(sizeof(struct Node));
		int *val = malloc(sizeof(int));
		*val = i;
		new_node->data = val;
		new_node->link = NULL;

		if (head == NULL) {
			head = new_node;
		} else {
			tail->link = new_node;
		}
		tail = new_node;
	}

	if (tail) {
		tail->link = head;
	}

	struct Node *current = head;
	int i = 0;
	if (head) {
		do {
			printf("Node[%d] -> data = %d\n", i++, *(int *)current->data);
			current = current->link;
		} while (current != head);
	}

	return 0;
}
