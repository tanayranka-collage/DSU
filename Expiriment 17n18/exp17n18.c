// code by Prof. Mrunal Fatangare Mam subject: Data Structures and Units in C - DSU SYCSE
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} node;

node *createNode(int da){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = da;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *insert(node* root,int d){
    if(root = NULL){
        return createNode(d);
    }
    if(d < root->data){
        root->left = insert(root->left, d);
    }
    else if(d > root->data){
        root->right = insert(root->right, d);
    }
    return root;
}

void 

int main(){



    
    return 0;
}
