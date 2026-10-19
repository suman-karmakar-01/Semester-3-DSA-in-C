#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int data;
    struct ListNode* next;
};

struct ListNode* head = NULL;

void reverse(){
    if(head == NULL) return;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
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

    display(); // 2 3 10 5
    reverse();
    display(); // 5 10 3 2
}