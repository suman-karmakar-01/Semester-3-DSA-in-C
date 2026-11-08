#include<stdio.h>

struct ListNode{
    int val;
    struct ListNode* next;
};

struct ListNode* head = NULL;

void reverse(struct ListNode* curr){
    if(curr->next == NULL){
        head = curr;
        return;
    }
    reverse(curr->next);
    struct ListNode* temp = curr->next;
    temp->next = curr;
    curr->next = NULL;
}

void display(){
    struct ListNode* temp = head;
    while(temp!=NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct ListNode N[4] = {{4, &N[1]},{5, &N[2]},{3, &N[3]},{2, NULL}};
    head = &N[0];

    display();//4 5 3 2
    reverse(head);
    display();
}