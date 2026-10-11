//code by tanay ranka sycse b 8
#include <stdlib.h>
#include <stdio.h>

#define MAX 100

void display(int* q, int* f, int* r){
    if (*f <= -1 || *r <= -1){
        printf("empty\n");
        return;
    }else{
        for(int i= *f;i<= *r;i++){
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

void enqueue(int* q, int *f, int* r, int data){
    if(*r >= MAX-1 || *f >= MAX-1){
        printf("overflow");
        return;
    }else{
        if(*f <= -1){
            *f = 0;
        }
        (*r)++;
        q[*r] = data;
    }
}

void dequeue(int* q, int* f, int* r){
    if(*f > -1 && *r > -1){
        q[*f] = 0;
        (*f)++;
    }else{
        printf("underrlow");
        return;
    }
}
int main() {
    size_t s = sizeof(int);
    int* queue = (int*)calloc(MAX, s);
    int front = -1;
    int rear = -1;
    int *f = &front;
    int *r = &rear;
    enqueue(queue, f, r, 10);
    enqueue(queue, f, r, 20);
    enqueue(queue, f, r, 30);
    dequeue(queue, f, r);
    enqueue(queue, f, r, 40);
    enqueue(queue, f, r,50);
    dequeue(queue, f, r);
    display(queue, f, r);
    

    


    free(queue);
    return 0;
}
