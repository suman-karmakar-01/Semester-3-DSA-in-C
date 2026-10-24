#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int data;
    struct ListNode* prev;
    struct ListNode* next;
};

struct ListNode* head = NULL;
int count = 0;

void insertBeginning(int data){
    struct ListNode* temp = malloc(sizeof(struct ListNode));
    temp->data = data;
    temp->prev = NULL;
    temp->next = head;
    if(head!=NULL){
        head->prev = temp;
    }
    count++;
    head = temp;
}

void insertEnd(int data){
    struct ListNode* temp1 = malloc(sizeof(struct ListNode));
    struct ListNode* temp2 = head;
    temp1->data = data;
    temp1->next = NULL;
    if(head==NULL){
        temp1->prev = NULL;
        head = temp1;
    }else{
        while(temp2->next!=NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp1;
        temp1->prev = temp2;
    }
    count++;
}

void insert(int x, int data){
    if(x < 1 || x>(count+1)){
        printf("Invalid position!\n");
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
    temp1->prev = temp2;
    temp2->next->prev = temp1;
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
    struct ListNode N[4] = {{2, NULL, &N[1]}, {3, &N[0], &N[2]}, {10, &N[1], &N[3]}, {5, &N[2], NULL}};
    head = &N[0];
    count = 4;
    insertBeginning(1);
    display();
    insertEnd(9);
    display();
    insert(7,11);
    display();
}
