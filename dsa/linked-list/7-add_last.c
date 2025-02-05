#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *link;
};

static void add_last(struct Node **head, int data);

static void add_last(struct Node **head, int data) {
	// Create a new node
	struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->link = NULL;

	// If the list is empty, make the new node the head
	if (*head == NULL) {
		*head = new_node;
		return;
	}

	// Traverse to the last node
	struct Node *current = *head;
	while (current->link != NULL) {
		current = current->link;
	}

	// Link the new node at the end
	current->link = new_node;
}

void print_list(struct Node *head) {
	struct Node *current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->link;
	}
	printf("NULL\n");
}

int main() {
	struct Node *head = (struct Node *)malloc(sizeof(struct Node));
	head->data = 1;
	head->link = (struct Node *)malloc(sizeof(struct Node));
	head->link->data = 2;
	head->link->link = (struct Node *)malloc(sizeof(struct Node));
	head->link->link->data = 3;
	head->link->link->link = NULL;

	// Print the initial list
	printf("Initial list: ");
	print_list(head);

	// Add a new node with data 4 at the end
	add_last(&head, 4);

	// Print the updated list
	printf("Updated list after adding 4: ");
	print_list(head);

	// Free the allocated memory (not shown for brevity)
	return 0;
}
