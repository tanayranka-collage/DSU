//code by tanay ranka sycse b 8
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100
bool isEmpty(int *top) {
    return *top == -1;
}

void push(char *stack, int *top, char data) {
    if (*top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }

    (*top)++;
    stack[*top] = data;
}

void pop(char *stack, int *top) {
    if (isEmpty(top)) {
        printf("Stack underflow\n");
        return;
    }

    (*top)--;
}

bool isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')')
        return true;

    if (opening == '[' && closing == ']')
        return true;

    if (opening == '{' && closing == '}')
        return true;

    return false;
}

int main() {
    char *stack = calloc(MAX, sizeof(char));

    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    char exp[MAX];
    int top = -1;
    bool flag = true;

    printf("Enter expression: ");
    fgets(exp, sizeof(exp), stdin);

    // Remove newline
    exp[strcspn(exp, "\n")] = '\0';

    for (int i = 0; exp[i] != '\0'; i++) {

        // Opening brackets
        if (exp[i] == '(' ||
            exp[i] == '[' ||
            exp[i] == '{') {

            push(stack, &top, exp[i]);
        }

        // Closing brackets
        else if (exp[i] == ')' ||
                 exp[i] == ']' ||
                 exp[i] == '}') {

            // No opening bracket available
            if (isEmpty(&top)) {
                flag = false;
                break;
            }

            // Check whether brackets match
            if (!isMatchingPair(stack[top], exp[i])) {
                flag = false;
                break;
            }

            // Matching pair found, so pop
            pop(stack, &top);
        }
    }

    // If stack is not empty, some opening brackets are unmatched
    if (!isEmpty(&top)) {
        flag = false;
    }

    if (flag) {
        printf("Correct expression\n");
    } else {
        printf("Incorrect expression\n");
    }

    free(stack);

    return 0;
}


