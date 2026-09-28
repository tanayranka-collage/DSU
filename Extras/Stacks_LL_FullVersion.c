// includes all nesecary functions needed to implement Stack Data Structure in C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack{
    struct Stack *prev;
    char data;
} s;

void pop(s** ref){
    if(*ref == NULL){
        printf("Empty List.\n");
    }
    s* temp = *ref;
    *ref = temp->prev;
    free(temp);
}

char peek(s **ref){
    if(*ref == NULL){
        return '\0';
    }
    return (*ref)->data;
}

bool isEmpty(s** ref){
    if(*ref == NULL){
        return true;
    }else{
        return false;
    }
}

s *push(s** ref, char d){
    s* neww = (s*)malloc(sizeof(s));
    neww->data = d;
    neww->prev = *ref;
    *ref = neww;
    return neww;
}

void clearStack(s **ref){
    if(*ref == NULL){
        return;
    }
    while(*ref != NULL){
        s* t = *ref;
        *ref = t->prev;
        free(t);
    }
    
}

void Display(s **ref){
    if(*ref == NULL){
        printf("NULL");
        return;
    }
    s* t = *ref;
    while(t != NULL){
        printf("Token: %c\n", t->data);
        t = t->prev;
    }
    printf("\n");
}

int main() {
    size_t si = sizeof(s);
    s* fir = (s*)malloc(si);
    s* sec = (s*)malloc(si);
    s* th = (s*)malloc(si);

    s *top = th;
    fir->prev = NULL;
    fir->data = ')';
    sec->prev = fir;
    sec->data = 'b';
    th->prev = sec;
    th->data = '+';

    // printf("%c\n", peek(&top));
    Display(&top);
    s* n = push(&top, 'a');
    s *nn = push(&top, '(');
    s *ff = push(&top, 'g');
    pop(&top);
    Display(&top);

    
    clearStack(&top);
    if(isEmpty(&top)){
        printf("Stack is empty.\n");
    }else{
        printf("Stack not empty.\n");
    }
    Display(&top);
    return 0;
}
