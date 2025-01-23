#include <stdio.h>
#include <stdlib.h>

struct node *add_middle(struct node *, int, int);

/* Struct node */
struct node {
    int data;
    struct node *link;
};

/* NODE FUNCTION */
struct node
*add_middle(struct node *head, int d, int position)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = d;
    new_node->link = NULL;

    // If the list is empty or position is 0, add at the beginning
    if (head == NULL || position == 0) {
        new_node->link = head;
        return new_node; // New node becomes the new head
    }

    struct node *current = head;
    int count = 0;

    // Traverse to the node just before the desired position
    while (current != NULL && count < position - 1) {
        current = current->link;
        count++;
    }

    // If current is NULL, position is greater than the length of the list
    if (current == NULL) {
        // Optionally, you can handle this case (e.g., add at the end)
        free(new_node); // Free the allocated memory for the new node
        return head; // Return the unchanged list
    }

    // Insert the new node
    new_node->link = current->link; // Link new node to the next node
    current->link = new_node; // Link current node to the new node

    return head; // Return the head of the list
}

int main()
{
    struct node *head = NULL; // Start with an empty list

    // Adding nodes to the list
    head = add_middle(head, 10, 0); // Add 10 at position 0
    head = add_middle(head, 20, 1); // Add 20 at position 1
    head = add_middle(head, 15, 1); // Add 15 at position 1 (middle)

    // Print the list
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");

    return 0;
}
