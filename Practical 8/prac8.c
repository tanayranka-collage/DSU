//code by tanay ranka sycse b 8
#include <stdlib.h>
#include <stdio.h>
struct Node{
    int data;
    struct Node *next;
};
void Print(struct Node** ref){
    struct Node *t = *ref;
    while(t != NULL){
        printf("Data: %d\n", t->data);
        t = t->next;
    }
    free(t);
    printf("\n");
}

struct Node* add_last(struct Node** ref, int d){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    struct Node *t = *ref;
    while(t->next != NULL){
        t = t->next;
    }
    t->next = n;
    n->data = d;
    n->next = NULL;
    return n;
    free(t);
}

struct Node* add_start(struct Node** ref, int d){
    struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = d;
    nn->next = *ref;
    *ref = nn;
    return nn;
}

void Search(struct Node** ref, int target){
    struct Node* t = *ref;
    int count = 0;
    while (t->next != NULL){
        if(t->data == target){
            printf("gottcha: at pos: %d", count+1);
            break;
        }
        t = t->next;
        count++;
    }
}

struct Node* add_n(struct Node** ref, int d, int pos){
    struct Node *t = *ref;
    struct Node* newN = (struct Node*)malloc(sizeof(struct Node));
    for(int i=0;i<pos-1;i++){
        t = t->next;
    }
    newN->next = t->next;
    t->next = newN;
    newN->data = d;
    return newN;
    free(t);
}

int main() {
    struct Node* fir = (struct Node*)malloc(sizeof(struct Node));
    struct Node* sec = (struct Node*)malloc(sizeof(struct Node));
    struct Node* th = (struct Node*)malloc(sizeof(struct Node));
    struct Node *head = fir;
    fir->data = 10;
    fir->next = sec;
    sec->data = 20;
    sec->next = th;
    th->data = 30;
    th->next = NULL;

    struct Node* sus = add_n(&head, 69, 2);
    struct Node* last = add_last(&head, 100);
    Print(&head);
    Search(&head, 30);


    free(fir);
    free(sec);
    free(th);
    return 0;
}

