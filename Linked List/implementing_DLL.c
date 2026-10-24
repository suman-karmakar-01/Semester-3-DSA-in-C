#include<stdio.h>

struct ListNode{
    int data;
    struct ListNode* prev;
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
    struct ListNode N[3] = {{2, NULL, &N[1]}, {3, &N[0], &N[2]}, {5, &N[1], NULL}};
    head = &N[0];
    display();
}
