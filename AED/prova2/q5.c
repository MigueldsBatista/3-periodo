#include <stdio.h>

#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node *left;
    struct Node*right;
}Node;
int similar(Node *root);
int check(Node *root);


void insert(Node **root, int value){
    if(*root==NULL){
        *root=(Node*)malloc(sizeof(Node));
        (*root)->data=value;
        (*root)->left=NULL;;
        (*root)->right=NULL;
    }else{
        if(value < (*root)->data){
            insert(&(*root)->left, value);
        }
        else if(value > (*root)->data){
            insert(&(*root)->right, value);
        }
    }
}

int main(){

    Node *root=NULL;
    insert(&root, 6);
    insert(&root, 4);
    insert(&root, 2);
    insert(&root, 8);
    insert(&root, 8);
    insert(&root, 12);
    insert(&root, 1);
    insert(&root, 3);
    
    int Issimilar = similar(root);
    printf("[%d]", Issimilar);
    return 0;

}
int similar(Node *root){

    int left = check(root->left);
    int right = check(root->right);
    return left!=right?0:-1;
}

int check(Node *root){
    if(root==NULL){
        return 0;
    }
    else{
        int left_nodes=check(root->left);
        int right_noodes=check(root->right);
        return left_nodes+right_noodes+1;
    }
}
