#include <stdlib.h>
#include <stdio.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node* add_st(struct Node** ref, int d){
    struct Node* newN = (struct Node*)malloc(sizeof(struct Node));
    newN->prev = NULL;
    newN->data = d;
    struct Node* t = *ref;
    t->prev = newN;
    newN->next = *ref;
    *ref = newN;
    return newN;
    free(t);
}
struct Node* add_lt(struct Node** ref, int d){
    struct Node* newn = (struct Node*)malloc(sizeof(struct Node));
    newn->data = d;
    newn->next = NULL;
    struct Node* t = *ref;
    while(t->next != NULL){
        t = t->next;
    }
    newn->prev = t;
    t->next = newn;
    return newn;

}

void del_st(struct Node** hed){
    struct Node* t = *hed;
    t = t->next;
    t->prev = NULL;
    *hed = t;
}

void del(struct Node** ref){
    struct Node* t = *ref;
    while(t->next != NULL){
        t = t->next;
    }
    // struct Node* n = t;
    // free(n);
    t = t->prev;
    t->next = NULL;
    // free(t);
}

void print(struct Node** ref){
    struct Node *t = *ref;
    while(t != NULL){
        printf("Data: %d\n", t->data);
        t = t->next;
    }
    free(t);
}

int main() {
    struct Node* f = (struct Node*)malloc(sizeof(struct Node));
    struct Node* s = (struct Node*)malloc(sizeof(struct Node));
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    struct Node *head = f;
    f->prev = NULL;
    f->data = 20;
    f->next = s;
    s->prev = f;
    s->data = 30;
    s->next = t;
    t->prev = s;
    t->data = 40;
    t->next = NULL;
    print(&head);
    printf("\n");
    struct Node* start = add_st(&head, 10);
    print(&head);
    printf("\n");
    del(&head);
    print(&head);
    printf("\n");
    struct Node* last = add_lt(&head, 40);
    print(&head);
    del_st(&head);
    printf("\n");
    print(&head);

    free(f);
    free(s);
    free(t);
    // free(head);
    return 0;
}
