#include <stdio.h>
#include <stdlib.h>

struct Node {
    void *data;
    struct Node *link;
};

void add_at_starting(void *data, struct Node *head)
{
    struct Node *current = head;
    current = head;

    while (current->link != head) {
        current = current->link;
    }
}

int main(void)
{
    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    int *data_1 = (int *) malloc(sizeof(int));
    *data_1 = 1;
    head->data = data_1;

    struct Node *ptr_1 = (struct Node *) malloc(sizeof(struct Node));
    int *data_2 = (int *) malloc(sizeof(int));
    *data_2 = 2;
    ptr_1->data = data_2;
    head->link = ptr_1;

    struct Node *ptr_2 = (struct Node *) malloc(sizeof(struct Node));
    int *data_3 = (int *) malloc(sizeof(int));
    *data_3 = 3;
    ptr_2->data = data_3;
    ptr_1->link = ptr_2;

    int *data_4 = (int *) malloc(sizeof(int));
    *data_4 = 4;

    add_at_starting(data_4, head);

    return 0;
}
