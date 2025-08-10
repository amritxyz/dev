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

int main(int argc, char **argv)
{
	struct Node *ptr_1 = malloc(sizeof(struct Node));
	u32 *data_1 = malloc(sizeof(u32));
	*data_1 = 1;
	ptr_1->data = data_1;

	struct Node *ptr_2 = malloc(sizeof(struct Node));
	u32 *data_2 = malloc(sizeof(u32));
	*data_2 = 2;
	ptr_2->data = data_2;
	ptr_1->link = ptr_2;

	struct Node *ptr_3 = malloc(sizeof(struct Node));
	u32 *data_3 = malloc(sizeof(u32));
	*data_3 = 3;
	ptr_3->data = data_3;
	ptr_2->link = ptr_3;
	
	ptr_3->link = NULL;

	if (!(ptr_1 || ptr_2 || ptr_3 || data_1 || data_2 || data_3)) {
		fprintf(stderr, "Memory allocation error!");
		return -1;
	}

	struct Node *current = ptr_1;
	while (current != NULL) {
		printf("%p = %d\n", current, *(u32 *)current->data);
		current = current->link;
	}

	return 0;
}
