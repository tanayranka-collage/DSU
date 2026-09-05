// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node* add_ben(struct Node** headref, int d){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->next = *headref;
    *headref = newNode;
    return newNode;
}


void print(struct Node** headr){
    struct Node *t = *headr;
    while (t != NULL){
        printf("data: %d\n", t->data);
        t = t->next;
    }
    free(t);
}

int main() {
    struct Node *first = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head = first;
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));
    first->data = 20;
    first->next = second;
    second->data = 30;
    second->next = third;
    third->data = 40;
    third->next = NULL;
    print(&head);
    struct Node *beg = add_ben(&head, 10);
    printf("\n");
    print(&head);

    free(first);
    free(second);
    free(third);
    free(head);
    

    return 0;
}
