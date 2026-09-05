#include <stdlib.h>
#include <stdio.h>
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node* insert_beg(struct Node **headr, int d){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->prev = NULL;
    newNode->data = d;
    newNode->next = *headr;
    struct Node *t = *headr;
    (*headr)->prev = newNode;
    *headr = newNode;
    return newNode;
    free(t);
}

struct Node* insert_end(struct Node** headr, int d){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    

    struct Node *temp = *headr;
    while(temp->next != NULL){
        temp = temp->next;
    }
    newNode->prev = temp;
    newNode->data = d;
    newNode->next = NULL;
    temp->next = newNode;
    //free(temp);
    return newNode;
    free(temp);
}

void print(struct Node **headref){
    struct Node *t = *headref;
    while(t != NULL){
        printf("Data: %d\n", t->data);
        t = t->next;
    }
    free(t);
}

void printv2(struct Node** headf){
    struct Node* g = *headf;
    while(g->next != NULL){
        g = g->next;
    }
    while(g->prev != NULL){
        printf("data: %d\n", g->data);
        g = g->prev;
    }
    printf("data: %d", g->data);
    free(g);
}

int main() {
    struct Node *first = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));
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
    struct Node *neww = insert_beg(&head, 10);
    print(&head);
    printf("\n");
    struct Node *last = insert_end(&head, 50);
    print(&head);

    printv2(&head);


    
    free(first);
    free(second);
    free(third);
    return 0;
}
