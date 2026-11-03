#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    char data[10];
    struct Node* prev;
    struct Node* next;
};

struct Node N[8];

struct Node* head = NULL;
struct Node* curr_song = NULL;
int count = 0;
int curr_loc = 0;

void menu(){
    printf("|==============|\n");
    printf("| 1. Next Song |\n");
    printf("| 2. Prev Song |\n");
    printf("| 3. Curr Song |\n");
    printf("| 4. Playlist  |\n");
    printf("| 5. Exit      |\n");
    printf("|==============|\n");
}

void next(){
    if(curr_song == NULL){
        printf("No song available!\n");
        return;
    }
    
    if(curr_song->next == NULL){
        char q;
        printf("Your current Singly Linked List doesn't support going to the starting song!\n");
        printf("Do you want to make it Circular Linked List (Y/N) : ");
        scanf(" %c", &q);
        if(tolower(q) == 'y'){
            curr_song->next = &N[0];
        }
        else return;
    }

    curr_song = curr_song->next;
    curr_loc = (curr_loc % count) + 1;
    printf("Now playing song by : %s\n", curr_song->data);
}


void prev(){
    if(curr_song == NULL){
        printf("No song available!\n");
        return;
    }

    struct Node* temp = head;
    struct Node* temp2;
    char q;
    if(temp->next != NULL && temp->prev == NULL){
        printf("Do you wanna make it DCLL(Y/N) : ");
        scanf(" %c", &q);
        if(tolower(q) == 'y'){
            N[7].next = &N[0]; 
            do {
                temp2 = temp;
                temp = temp->next;
                temp->prev = temp2;
            } while(temp != head && temp != NULL);
            head->prev = temp2; 
            
            printf("List is now a DCLL.\n");
        }
        else return;
    }

    curr_song = curr_song->prev;
    curr_loc--;
    if(curr_loc == 0) curr_loc = 8;
    printf("Now playing song by : %s\n", curr_song->data);
}

void display(){
    struct Node* temp = head;
    if(head->prev == NULL){
        while(temp!=NULL){
            printf("%s\n", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    else{
        do{
            printf("%s\n", temp->data);
            temp = temp->next;
        }while(temp != head);
        printf("\n");
    }
}

struct Node N[8] = {
    {"50cent",    NULL, &N[1]},
    {"snoopdogg", NULL, &N[2]},
    {"biggie",    NULL, &N[3]},
    {"MJ",        NULL, &N[4]},
    {"2pac",      NULL, &N[5]},
    {"drdre",     NULL, &N[6]},
    {"popsmoke",  NULL, &N[7]},
    {"eazee",     NULL, NULL}
};

int main(){
    curr_loc = 1;
    count = 8;
    head = &N[0];
    curr_song = head;

    int choice = 1;
    do{
        menu();
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                next();
                break;
            case 2:
                prev();
                break;
            case 3:
                printf("Current Song's Artist : %s\n", curr_song->data);
                break;
            case 4:
                display();
                break;
            case 5:
                break;
            default:
                printf("Invalid Input!\n");
        }

    }while(choice != 5);

    printf("|============|\n");
    printf("| Thank You! |\n");
    printf("|============|\n");
}
