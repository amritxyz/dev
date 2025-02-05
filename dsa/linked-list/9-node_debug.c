#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node* link;
	void* data;
};

void print_node(struct Node* head) {
	// Cast data to int* and dereference it to get the value
	printf("%d -> ", *(int*)head->data);

	// Check if link is not NULL before dereferencing
	if (head->link != NULL) {
		printf("%p\n", (void*)head->link); // Print the address of the next node
	} else {
		printf("NULL\n");
	}
}

int main() {
	struct Node* head = malloc(sizeof(struct Node));
	if (head == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return 1;
	}

	// Allocate memory for the data and assign a value
	head->data = malloc(sizeof(int));
	if (head->data == NULL) {
		fprintf(stderr, "Memory allocation for data failed\n");
		free(head);
		return 1;
	}
	*(int*)head->data = 1; // Assign value to the allocated memory

	head->link = malloc(sizeof(struct Node));
	if (head->link == NULL) {
		fprintf(stderr, "Memory allocation for link failed\n");
		free(head->data);
		free(head);
		return 1;
	}
	head->link->data = NULL; // Initialize the link's data to NULL
	head->link->link = NULL; // Initialize the link's link to NULL

	print_node(head);

	// Free allocated memory
	free(head->link); // Free the second node
	free(head->data); // Free the data
	free(head);       // Free the head node

	return 0;
}
