#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int data;
    struct ListNode* next;
};

struct ListNode* head = NULL;
int count = 0;

void deleteBeginning(){
    if(head == NULL) return;
    struct ListNode* temp = head;
    if(head->next == head){
        head = NULL;
    }else{
        struct ListNode* last = head;
        while(last->next!=head){
            last = last->next;
        }
        head = head->next;
        last->next = head;
    }
    free(temp);
    count--;
}

void deleteEnd(){
    if(head == NULL) return;
    struct ListNode* temp1;
    struct ListNode* temp2 = head;
    if(head->next == head){
        head = NULL;
        free(temp2);
    }else{
        while(temp2->next->next!=head){
            temp2 = temp2->next;
        }
        temp1 = temp2->next;
        temp2->next = head;
        free(temp1);
    }
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
    temp1 = temp2->next;
    temp2->next = temp1->next;
    free(temp1);
    count--;
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
    deleteBeginning();
    display();
    deleteEnd();
    display();
    delete(2);
    display();
}
