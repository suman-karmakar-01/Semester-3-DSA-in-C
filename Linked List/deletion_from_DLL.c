#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int data;
    struct ListNode* prev;
    struct ListNode* next;
};

struct ListNode* head = NULL;
int count = 0;

void deleteBeginning(){
    if(head == NULL) return;
    struct ListNode* temp = head;
    head = head->next;
    if(head != NULL){
        head->prev = NULL;
    }
    free(temp);
    count--;
}

void deleteEnd(){
    if(head == NULL) return;
    struct ListNode* temp = head;
    if(head->next == NULL){
        head = NULL;
        free(temp);
    }else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
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
    if(temp1->next != NULL){
        temp1->next->prev = temp2;
    }
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
    struct ListNode N[4] = {{2, NULL, &N[1]}, {3, &N[0], &N[2]}, {10, &N[1], &N[3]}, {5, &N[2], NULL}};
    head = &N[0];
    count = 4;
    deleteBeginning();
    display();
    deleteEnd();
    display();
    delete(2);
    display();
}
