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
    if(head == NULL){
        head = temp;
        temp->next = head;
    }else{
        struct ListNode* temp2 = head;
        while(temp2->next!=head){
            temp2 = temp2->next;
        }
        temp->next = head;
        temp2->next = temp;
        head = temp;
    }
    count++;
}

void insertEnd(int data){
    struct ListNode* temp1 = malloc(sizeof(struct ListNode));
    temp1->data = data;
    if(head == NULL){
        head = temp1;
        temp1->next = head;
    }else{
        struct ListNode* temp2 = head;
        while(temp2->next!=head){
            temp2 = temp2->next;
        }
        temp2->next = temp1;
        temp1->next = head;
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
    temp2->next = temp1;
    count++;
}

void display(){
    if(head == NULL) return;
    struct ListNode* temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp!=head);
    printf("\n");
}

int main(){
    struct ListNode N[4] = {{2, &N[1]}, {3, &N[2]}, {10, &N[3]}, {5, &N[0]}};
    head = &N[0];
    count = 4;
    insertBeginning(1);
    display();
    insertEnd(9);
    display();
    insert(7,11);
    display();
}
