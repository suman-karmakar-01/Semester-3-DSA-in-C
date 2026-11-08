#include<stdio.h>
#include<stdlib.h>

struct BSTnode{
    int data;
    struct BSTnode* left;
    struct BSTnode* right;
};

struct BSTnode* root = NULL;

struct BSTnode* newNode(int data){
    struct BSTnode* newNode = malloc(sizeof(struct BSTnode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct BSTnode* insert(struct BSTnode* root, int data){
    if(root == NULL) return newNode(data);
    if(root->data >= data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

void preorder(struct BSTnode* root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main(){
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);

    preorder(root);
}