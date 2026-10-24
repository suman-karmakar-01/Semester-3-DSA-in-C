#include<stdio.h>

struct ListNode{
    int data;
    struct ListNode* next;
};

struct ListNode* head = NULL;

void display(){
    if(head == NULL) return;
    struct ListNode* temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp!=head);
}

int main(){
    struct ListNode N[3] = {{2, &N[1]}, {3, &N[2]}, {5, &N[0]}};
    head = &N[0];
    display();
}
