// LL explanation here
#include <stdio.h>
#include <stdlib.h>
struct s{
    int data;
    struct s *hello; // this own struct's pointer 
};

int main() {
    struct s *head = NULL;
    struct s *second = NULL;
    head = (struct s*)malloc(sizeof(struct s));
    second = (struct s *)malloc(sizeof(struct s));
    head->data = 56;     //-> operator reiniliases its own pointnig addr to specified attribute of the struct or union.
    second->data = 69;
    head->hello = second;
    second->hello = NULL;

    printf("Linked List\n");
    struct s *temp = head;
    while(temp != NULL){
        printf("%p = :%d: ->> \n", temp, temp->data);
        temp = temp->hello;
    }
    //freeing 
    temp = head;
    while(temp != NULL){
        struct s *tempo = temp->hello;
        free(temp);
        temp = tempo;
    }


    return 0;
}
