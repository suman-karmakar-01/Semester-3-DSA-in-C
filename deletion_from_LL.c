#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int data;
    struct ListNode* next;
};

struct ListNode* head = NULL;
int count = 0;

void deleteBeginning(){
    struct ListNode* temp = head;
    if(head == NULL) return;
    temp = head;
    head = head->next;
    free(head);
    count--;
}

void deleteEnd(){
    struct ListNode* temp1;
    struct ListNode* temp2 = head;
    while(temp2->next!=NULL && temp2->next->next!=NULL){
        temp2=temp2->next;
    }
    temp1 = temp2->next;
    temp2->next = NULL;
    free(temp1);
    count--;
}

void delete(int x){
    if(x < 1 || x > count){
        printf("Invalid position!\n");
        return;
    }
    if(x==1){
        deleteBeginning();
        return;
    }
    if(x==count){
        deleteEnd();
        return;
    }
    struct ListNode* temp1;
    struct ListNode* temp2 = head;
    for(int i=1; i<x-1; i++){
        temp2 = temp2->next;
    }
    temp1 = temp2;
    temp2->next = temp2->next->next;
    free(temp1);
    count--;
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
    deleteBeginning();
    display();
    deleteEnd();
    display();
    delete(2);
    display();
}