//just a representation of Stacks Data Structure using Concept of Linked List 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> // optional

struct Stack{
    struct Stack *prev;
    char data;                         
};                       //defines the structure of a single node of the stack

void Display(struct Stack** top_ref){
    struct Stack *temp = *top_ref;
    while(temp != NULL){
        printf("Token: %c\n", temp->data);
        temp = temp->prev;
    }
    printf("\n");
    free(temp);
}

struct Stack* push(struct Stack** top_ref, char d){
    struct Stack *newElem = (struct Stack*)malloc(sizeof(struct Stack));
    newElem->prev = *top_ref;
    newElem->data = d;
    *top_ref = newElem;
    return newElem;
}

void pop(struct Stack** top_ref){
    struct Stack *temp = *top_ref;
    *top_ref = temp->prev;
    free(temp);
}

int main(){
    size_t size = sizeof(struct Stack);
    struct Stack *elem1 = (struct Stack*)malloc(size);
    struct Stack *elem2 = (struct Stack*)malloc(size);
    struct Stack *elem3 = (struct Stack*)malloc(size);
    struct Stack *elem4 = (struct Stack*)malloc(size);
    struct Stack *elem5 = (struct Stack*)malloc(size);

    struct Stack *top = elem5;

    elem5->prev = elem4;
    elem5->data = '(';
    elem4->prev = elem3;
    elem4->data = 'a';
    elem3->prev = elem2;
    elem3->data = '+';
    elem2->prev = elem1;
    elem2->data = 'b';
    elem1->prev = NULL;
    elem1->data = ')';

    Display(&top);
    struct Stack *elem6 = push(&top, '1');
    Display(&top);
    pop(&top);
    Display(&top);


    sleep(2);
    free(elem1);
    free(elem2);
    free(elem3);
    free(elem4);
    free(elem5);

    return 0;
}
