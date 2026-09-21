#include<stdio.h>
#define MAX 5
int top=-1;
int stack[MAX];

int isFull(){
    return top==MAX-1;
}

int isEmpty(){
    return top==-1;
}

void push(int val){
    if(isFull()) printf("Stack Full\n");
    else{
        top++;
        stack[top] = val;
    }
}

void pop(){
    if(isEmpty()) printf("Stack is empty\n");
    else top--;
}

void peek(){
    if(isEmpty()){
        printf("Stack is empty!\n");
        return;
    }
    printf("Peeked top of the stack and found : %d\n", stack[top]);
}

void display(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return;
    }
    printf("|----|\n");
    for(int i=top; i>=0; i--) printf("| %d |\n", stack[i]);
    printf("|----|");
    printf("\n\n");
}

int main(){
    pop();
    push(10);
    push(20);
    push(30);
    display();
    push(40);
    peek();
    push(51);
    peek();
    push(60);
    display();
    peek();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    pop();
    display();
    return 0;
}