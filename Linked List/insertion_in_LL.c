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
    if(temp == NULL) return;
    temp->data = data;
    temp->next = head;
    count++;
    head = temp;
}

void insertEnd(int data){
    struct ListNode* temp1 = malloc(sizeof(struct ListNode));
    if(temp1 == NULL) return;
    temp1->data = data;
    temp1->next = NULL;
    if(head == NULL){
        head = temp1;
        count++;
        return;
    }
    struct ListNode* temp2 = head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next = temp1;
    count++;
}

void insert(int x, int data){
    if(x < 1 || x > (count+1)){
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
    if(temp1 == NULL) return;
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
    insert(4,7);
    insert(5,11);
    display();
}
