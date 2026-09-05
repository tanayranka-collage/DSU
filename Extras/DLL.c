#include <stdlib.h>
#include <stdio.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node* insert_beg(struct Node **headr, int d) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->prev = NULL;
    newNode->data = d;
    newNode->next = *headr;

    if (*headr != NULL) {
        (*headr)->prev = newNode;
    }

    *headr = newNode;

    return newNode;
}

struct Node* insert_end(struct Node **headr, int d) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = d;
    newNode->next = NULL;

    // Empty list
    if (*headr == NULL) {
        newNode->prev = NULL;
        *headr = newNode;
        return newNode;
    }

    struct Node *temp = *headr;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    newNode->prev = temp;
    temp->next = newNode;

    return newNode;
}

void print(struct Node **headref) {
    struct Node *t = *headref;

    while (t != NULL) {
        printf("Data: %d\n", t->data);
        t = t->next;
    }
}

int main() {

    struct Node *first = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    struct Node *head = first;

    first->prev = NULL;
    first->data = 20;
    first->next = second;

    second->prev = first;
    second->data = 30;
    second->next = third;

    third->prev = second;
    third->data = 40;
    third->next = NULL;

    print(&head);

    printf("\n");

    insert_beg(&head, 10);

    print(&head);

    printf("\n");

    insert_end(&head, 50);

    print(&head);

    // Free entire list
    struct Node *temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
