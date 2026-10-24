#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int data;
    struct ListNode* next;
};

struct ListNode* head = NULL;
int count = 0;

void insertBeginning(int data){
    struct ListNode* temp = malloc(sizeof(struct ListNode));
    temp->data = data;
    temp->next = head;
    count++;
    head = temp;
}

void insertEnd(int data){
    struct ListNode* temp1 = malloc(sizeof(struct ListNode));
    struct ListNode* temp2 = head;
    temp1->data = data;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next = temp1;
    temp1->next = NULL;
    count++;
}

void insert(int x, int data){
    if(x < 1 || x>(count+1)){
        printf("Invlaid position!\n");
        return;
    }
    if(x==1){
        insertBeginning(data);
        return;
    }
    if(x==count+1){
        insertEnd(data);
        return;
    }
    struct ListNode* temp1 = malloc(sizeof(struct ListNode));
    struct ListNode* temp2 = head;
    temp1->data = data;
    for(int i=1; i<x-1; i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    count++;
}

void display(){
    struct ListNode* temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct ListNode N[4] = {{2, &N[1]}, {3, &N[2]}, {10, &N[3]}, {5, NULL}};
    head = &N[0];
    count = 4;
    insertBeginning(1);
    display();
    insertEnd(9);
    display();
    insert(7,11);
    display();
}