

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void display(char* ref, int* top){
    if(*top < -1 || *top >= MAX){
        printf("empty stack\n");
        return;
    }
    for(int i= *top;i>=0;i--){
      printf("%c\n", ref[i]);
    }
    printf("\n");
}

void pop(char* ref, int* top){
    if(*top < -1 || *top >= MAX){
        printf("underflow\n");
        return;
    }
    ref[*top] = '\0';
    (*top)--;
}
void push(char* ref, int* top, char data){
    if(*top >= MAX-1 || *top < -1){
        printf("overflow\n");
        return;
    }
    (*top)++;
    ref[*top] = data;
}

void clear(char* ref, int* top){
    for(int i= *top;i>=0;i--){
        ref[i] = '\0';
    }
    *top = -1;
}

int main() {
    size_t s = sizeof(char);
    char *stack = (char*)calloc(MAX, s);
    int top = -1;
    int *t = &top;
    push(stack, t, ')');
    push(stack, t, 'b');
    push(stack, t, '+');
    push(stack, t, 'a');
    push(stack, t, '(');
    push(stack, t, 'f');
    pop(stack, t);
    display(stack, t);

    clear(stack, t);
    free(stack);
    
    return 0;
}
