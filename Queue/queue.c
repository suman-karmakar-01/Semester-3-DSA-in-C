#include<stdio.h>
#define MAX 5
int front = -1;
int rear = -1;
int queue[MAX];

int isFull(){
    return rear == MAX - 1;
}

int isEmpty(){
    return front == -1;
}

void enqueue(int val){
    if(isFull()) printf("Queue Full\n");
    else{
        if(front == -1) front = 0;
        rear++;
        queue[rear] = val;
    }
}

void dequeue(){
    if(isEmpty()) printf("Queue Empty\n");
    else{
        front++;
        if(front>rear) front=rear=-1;
    }
}

void display(){
    if(isEmpty()){
        printf("Queue Empty\n");
        return;
    }
    for(int i=front; i<=rear; i++) printf("%d ", queue[i]);
    printf("\n");
}

int main(){
    dequeue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    dequeue();
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
    return 0;
}