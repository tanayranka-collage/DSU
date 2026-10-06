#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

long int count_even(struct Node **ref){
  long int count = 0;
  struct Node *t = *ref;
    while(t != NULL){
        if(t->data %2 == 0){
            count++;
        }
        t = t->next;
    }
    return count;
}

long int count_odd(struct Node **ref){
  long int c = 0;
  struct Node *t = *ref;
  while(t != NULL){
    if(!(t->data %2 == 0)){
      c++;
    }
    t = t->next;
  }
  return c;
}
