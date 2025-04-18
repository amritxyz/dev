/*
 * INFO: Adding node as head in circular linked-list
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    void *data;
    struct Node *link;
};

int
add_at_beginning(void *data, struct Node *head)
{
    struct Node *current = head;
    current = head;

    // class wala
    while (current->link != head) {
        current = current->link;
    }

    // Adding
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->link = head; // dimag kharab after 30 minutes
    current->link = new_node;

    // Swap data with head
    void *temp = head->data;
    head->data = new_node->data;
    new_node->data = temp;

    current = head;

    // int i = 1;
    // while (current != head) {
    //   printf("node[%d] = %d\n", i++, *(int *)current->data);
    //   current = current->link;
    // }

    // While loop is not printing cause we need to run body first # Just read the documentation
    int i = 1;
    do {
        printf("node[%d]->[%d] = %d\n", i++, current->link, *(int *)current->data);
        current = current->link;
    } while (current != head);

    return 0;
}

int main(void)
{
    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    int *data1 = (int *) malloc(sizeof(int));
    *data1 = 1;
    head->data = data1;
    // head->link = NULL;

    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    int *data2 = (int *) malloc(sizeof(int));
    *data2 = 2;
    ptr->data = data2;
    head->link = ptr;
    // ptr->link = NULL;

    struct Node *last = (struct Node*) malloc(sizeof(struct Node));
    int *data3 = (int *) malloc(sizeof(int));
    *data3 = 3;
    last->data = data3;
    // last->link = NULL;
    ptr->link = last;

    // curcle or last
    last->link = head;

    // fourth one
    int *data4 = malloc(sizeof(int));
    *data4 = 4;
    add_at_beginning(data4, head);

    struct Node *temp = head;
    struct Node *next;

    // Freeing using GNU method
    do {
        next = temp->link;
        free(temp->data);
        free(temp);
        temp = next;
    } while(temp != head);

    // printf("hell");
    //
    // add_at_beginning((int*) 4, head);
    //
    // free(head);
    // free(ptr);
    //
    return 0;
}
