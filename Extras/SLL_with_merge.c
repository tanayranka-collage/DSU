// Online C compiler to run C program online
#include<stdlib.h>
#include <stdio.h>
struct Node{
    int data;
    struct Node *next;
};

void DEL(struct Node** ref){
    struct Node* t = *ref;
    *ref = t->next;
    free(t);
}

void Print(struct Node** ref){
    struct Node* e = *ref;
    while(e != NULL){
        printf("Data: %d\n", e->data);
        e = e->next;
    }
    free(e);
}
void merge(struct Node** ref1, struct Node** ref2){
    struct Node* t = *ref1;
    while(t->next != NULL){
        t = t->next;
    }
    t->next = *ref2;
    *ref2 = *ref1;
}

struct Node* add(struct Node** ref, int d){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = d;
    n->next = *ref;
    *ref = n;
    return n;
}

int main() {
    struct Node* fir = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head = fir;
    fir->data = 24;
    fir->next = NULL;
    // Print(&head);
    struct Node* ne = add(&head, 42);
    struct Node* nnn = add(&head, 30);
    Print(&head);

    struct Node* a = (struct Node*)malloc(sizeof(struct Node));
    a->data = 40;
    a->next = NULL;
    struct Node* second = a;
    struct Node* b = add(&second, 55);
    printf("\n");
    Print(&second);
    printf("\n");
    merge(&head, &second);
    Print(&head);

    free(fir);
    free(a);

    return 0;
}
