//code 
#include <stdlib.h>
#include <stdio.h>
#define MAX 100

void Dis(int *Q, int* fr, int* re){
    if(*fr == -1 && *re == -1){
        printf("empty\n");
        return;
    }else{
        for(int i=*fr;i<=*re;i++){
            printf(" %d ", Q[i]);
        }
        printf("\n");
    }
}

void dequeue(int *Q, int* fr, int* re){
    if(*fr == -1 && *re == -1){
        printf("Invalid queue; empty\n");
        return;
    }else if(!(*fr > *re)){
        Q[*fr] = 0;
        (*fr)++;
    }else{
        printf("Invalid Queue\n");
        return;
    }
}

void enqueue(int* Q, int* fr, int* re, int data){
    if(*fr == -1 && *re == -1){
        (*fr)++;
        (*re)++;
        Q[*fr] = data;
    }else if(*re >= MAX - 1){
        printf("queue full");
        return;
    }else if(!(*fr > *re)){
        (*re)++;
        Q[*re] = data;
    }else{
        printf("invalid queue\n");
        return;
    }
}

int main() {
    size_t si = sizeof(int);
    int *queue = (int*)calloc(MAX, si);
    int f,r;
    f = -1;
    r = -1;
    Dis(queue, &f, &r);
    enqueue(queue, &f, &r, 10);
    enqueue(queue, &f, &r, 20);
    enqueue(queue, &f, &r, 30);
    enqueue(queue, &f, &r, 40);
    enqueue(queue, &f, &r, 50);
    enqueue(queue, &f, &r, 60);
    dequeue(queue, &f, &r);
    dequeue(queue, &f, &r);
    Dis(queue, &f, &r);

    
    free(queue);
    return 0;
}
