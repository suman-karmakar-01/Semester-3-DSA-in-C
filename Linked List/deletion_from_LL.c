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
    head = head->next;
    count--;
}

void deleteEnd(){
    if(head == NULL) return;
    struct ListNode* temp2 = head;
    if(head->next == NULL){
        head = NULL;
        count--;
        return;
    }
    while(temp2->next->next != NULL){
        temp2 = temp2->next;
    }
    temp2->next = NULL;
    count--;
}

void delete(int x){
    if(x < 1 || x > count){
        printf("Invalid position!\n");
        return;
    }
    if(x == 1){
        deleteBeginning();
        return;
    }
    if(x == count){
        deleteEnd();
        return;
    }
    struct ListNode* temp2 = head;
    for(int i = 1; i < x-1; i++){
        temp2 = temp2->next;
    }
    temp2->next = temp2->next->next;
    count--;
}

void display(){
    struct ListNode* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct ListNode N[4] = {
        {2, &N[1]},
        {3, &N[2]},
        {10, &N[3]},
        {5, NULL}
    };
    head = &N[0];
    count = 4;
    display();
    deleteBeginning();
    display();
    deleteEnd();
    display();
    delete(2);
    display();
}
