//prog to only add elements to a Linked List.
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node* add_first(struct Node* ptr,int val){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = ptr;
    return temp;
}
struct Node* add_last(struct Node* pr, int val){
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = val;
    t->next = NULL;
    pr->next = t;
    return t;
}
int main() {
    /*struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;*/
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));
    head->data = 24;
    head->next = second;
    second->data = 10;
    second->next = third;
    third->data = 26;
    third->next = NULL;

    struct Node* sex = add_first(head, 69);
    struct Node *tep = sex;
    struct Node* last = add_last(third, 99);
    while (tep != NULL){
        printf("data: %d\n", tep->data);
        tep = tep->next;
    }


    free(head);
    free(second);
    free(third);
    free(sex);
    free(last);
    return 0;
}
