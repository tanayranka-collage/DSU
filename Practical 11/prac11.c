//code by tanay ranka sycse b 8
#include <stdlib.h>
#include <stdio.h>

#define MAX 100

void Dis(int *ref, int* top){
    if (*top == -1){
        printf("underdlow\n");
        return;
    }
    for (int i = *top;i>=0;i--){
        printf("%d\n", ref[i]);
    }
    printf("\n");
}

void pop(int *ref, int* top_ref){
    if(*top_ref == -1){
        printf("stack underflow\n");
        return;
    }
    ref[*top_ref] = 0;
    (*top_ref)--;
}
void push(int* ref, int* top, int data){
    if (*top >= MAX-1){
        printf("overflow\n");
        return;
    }
    (*top)++;
    ref[*top] = data;  
}

void clear_stack(int* s, int* top){
    for(int i= *top;i>=0;i--){
        s[i] = 0;
    }
    *top = -1;
}
int main() {
    size_t s = sizeof(int);
    int *stack = (int*)calloc(MAX, s);
    int top = 6;
    for (int i=0;i<7;i++){
        stack[i] = i+1;
    }
    Dis(stack, &top);
    pop(stack, &top);
    Dis(stack, &top);
    push(stack, &top, 23);
    Dis(stack, &top);
    clear_stack(stack, &top);
    Dis(stack, &top);

    free(stack);
    return 0;
}
