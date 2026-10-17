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
    if(root == NULL){
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

void inorder(node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void preorder(node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    int n, value;
    node *root = NULL;
    printf("enter max length: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("enter Value: ");
        scanf("%d", &value);
        root = insert(root, value);
        
    }
    printf("\n");
    printf("Inorder: \n");
    inorder(root);
    printf("\n");
    printf("Postorder: \n");
    postorder(root);
    printf("\n");
    printf("Preorder: \n");
    preorder(root);


    
    return 0;
}
