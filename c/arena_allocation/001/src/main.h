#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

/*
 * INFO: Creating a linked list 
 *	 (Data, Link)
 */
typedef struct Node {
	int data;
	struct Node *link;
} Node;

/* INFO: Arena allocations */
typedef struct Arena {
	char *start;
	char *current;
	size_t size;
} Arena;

void init_arena(Arena *, size_t);
void *arena_alloc(Arena *, size_t);
void traverse(Node *);
void free_arena(Arena *);

#endif
