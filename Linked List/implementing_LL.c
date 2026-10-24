#include<stdio.h>

struct ListNode{
    int data;
    struct ListNode* next;
};

struct ListNode* head = NULL;

void display(){
    struct ListNode* temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){
    struct ListNode N[3] = {{2, &N[1]}, {3, &N[2]}, {5, NULL}};
    head = &N[0];
    display();
}