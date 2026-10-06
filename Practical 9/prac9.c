// code by tanay Ranka sycse b 8
#include<stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *next;
} sll;

void Display(sll ** ref){
    sll *t = *ref;
    while(t != NULL){
        printf("Data: %d\n", t->data);
        t = t->next;
    }
    printf("\n");
}

void del_start(sll **ref){
    sll *t = *ref;
    *ref = t->next;
    //free(t);
}
void del_end(sll **ref){
    sll *t = *ref;
    while (t->next->next != NULL){
        t = t->next;
    }
    t->next = NULL;
    //free(t);
    
}
void del_after(sll **ref, int pos){
    sll *t = *ref;
    for(int i=0;i<pos-1;i++){
        t = t->next;
    }
    if(t == NULL){
        printf("invalid position");
        return;
    }else{
        t->next = t->next->next;
        
    }
}


int main() {
    size_t v = sizeof(sll);
    sll *fir = (sll*)malloc(v);
    sll *sec = (sll*)malloc(v);
    sll *th = (sll*)malloc(v);
    sll *fr = (sll*)malloc(v);
    sll *fi = (sll*)malloc(v);
    sll *head = fir;

    fir->data = 10;
    fir->next = sec;
    sec->data = 20;
    sec->next = th;
    th->data = 30;
    th->next = fr;
    fr->data = 40;
    fr->next = fi;
    fi->next = NULL;
    fi->data = 50;
    Display(&head);
    del_after(&head, 3);
    Display(&head);
    del_start(&head);
    del_end(&head);
    Display(&head);


    free(fir);
    free(sec);
    free(th);
    free(fr);
    free(fi);
    
    return 0;
}
