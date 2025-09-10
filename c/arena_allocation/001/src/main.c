#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "main.h"

/* INFO: Chunks of memory arena allocator uses. */
#define ARENA_SIZE 1024

/*
 * INFO: Initializes the arena
 */
void
init_arena(Arena *arena, size_t size) {
	arena->start = (char *) malloc(size);
	if (!arena->start) {
		fprintf(stderr, "Arena allocation failed!\n");
		exit(1);
	}
	arena->current = arena->start;
	arena->size = size;
}

/*
 * INFO: Arena allocator function
 */
void
*arena_alloc(Arena *arena, size_t size) {
	if (
		arena->current + size 
		>
		arena->start + arena->size)
	{
		fprintf(stderr, "Warning: Arena allocation overflow!");
		exit(1);
	}
	void *ptr = arena->current;
	arena->current += size;
	return ptr;
}

/*
 * INFO: Linked list traverse function
 */
void traverse(Node *head)
{
	Node *current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->link;
	}
	printf("NULL\n");
}

/*
 * INFO: Free Arena
 */
void free_arena(Arena *arena)
{
	free(arena->start);
}

int
main(void)
{
	Arena arena;
	init_arena(&arena, ARENA_SIZE);

	Node *head = (Node *) arena_alloc(&arena, sizeof(Node));
	head->data = 1;

	Node *second = (Node *) arena_alloc(&arena, sizeof(Node));
	second->data = 2;
	head->link = second;

	second->link = NULL;

	traverse(head);

	free_arena(&arena);

	return 0;
}
