#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

//struct Node* root = NULL;

struct Node* newNode(int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data){
    if(root == NULL){
        root = newNode(data);
        return root;
    }
    if(data <= root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

int min(struct Node* root){
    if(root == NULL) return -1;
    struct Node* temp = root;
    while(temp->left!=NULL) temp = temp->left;
    return temp->data;
}

int max(struct Node* root){
    if(root == NULL) return -1;
    struct Node* temp = root;
    while(temp->right!=NULL) temp = temp->right;
    return temp->data;
}

int main(){
    struct Node* root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 8);
    root = insert(root, 12);
    printf("Min value : %d\n", min(root));
    printf("Max value : %d", max(root));
}