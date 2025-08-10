/*
 * INFO: Linked List (Traversing)
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <uchar.h>

#define u32 uint32_t
#define u64 uint64_t
#define u8  uint8_t
#define c16 uchar16_t
#define c32 uchar32_t

struct Node {
	void *data;
	struct Node *link;
};

void traverse(struct Node *);

void
traverse(struct Node *head)
{
	// INFO: Traverse and print.
	struct Node *current = head;
	while (current != NULL) {
		printf("%p = %d\n", current, *(u32 *)current->data);
		current = current->link;
	}
	exit(true);
}

int main(int argc, char **argv)
{
	// NOTE: First Node
	struct Node *ptr_1 = malloc(sizeof(struct Node));
	u32 *data_1 = malloc(sizeof(u32));
	if (!ptr_1 || !data_1) {
		fprintf(stderr, "Memory allocation failed for ptr_1 and data_1.");
		return -1;
	}
	*data_1 = 1;
	ptr_1->data = data_1;

	// INFO: Second Node.
	struct Node *ptr_2 = malloc(sizeof(struct Node));
	u32 *data_2 = malloc(sizeof(u32));
	*data_2 = 2;
	if (!ptr_2 || !data_2) {
		fprintf(stderr, "Memory allocation failed for ptr_2 and data_2.");
		free(ptr_1);
		free(data_1);
		return -1;
	}
	ptr_2->data = data_2;
	ptr_1->link = ptr_2;

	// INFO: Third Node.
	struct Node *ptr_3 = malloc(sizeof(struct Node));
	u32 *data_3 = malloc(sizeof(u32));
	if (!ptr_3 || !data_3) {
		fprintf(stderr, "Memory allocation failed for ptr_3 and data_3");
		free(ptr_1);
		free(ptr_2);
		free(data_1);
		free(data_2);
		return -1;
	}
	*data_3 = 3;
	ptr_3->data = data_3;
	ptr_2->link = ptr_3;
	
	// INFO: Last node pointing to NULL. (singly linked list)
	ptr_3->link = NULL;

	traverse(ptr_1);

	return 0;
}
