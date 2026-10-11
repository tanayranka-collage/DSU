//code by tanay ranka sycse b 8
#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *next;
} node;

void display(node **f){
    if(*f == NULL){
        printf("empty\n");
        return;
    }else{
        node *s = *f;
        while(s != NULL){
            printf("%d ", s->data);
            s = s->next;
        }
        printf("\n");
    }
}
void dequeue(node **f){
    if(*f == NULL){
        printf("underflow\n");
        return;
    }else{
        *f = (*f)->next;
    }
}
node *enqueue(node **f, node **r, int d){
    node *n = (node*)malloc(sizeof(node));
    n->data = d;
    if(*r == NULL){
        *r = n;
    }else{
        (*r)->next = n;
    }
    n->next = NULL;
    //*r = n;
    if(*f == NULL){
        *f = n;
    }
    return n;
}
int main() {
    node *front = NULL;
    node *rear = NULL;
    display(&front);
    node* fir = enqueue(&front, &rear, 10);
    node *sec = enqueue(&front, &rear, 20);
    node *th = enqueue(&front, &rear, 30);
    display(&front);
    dequeue(&front);
    display(&front);

    return 0;
}
