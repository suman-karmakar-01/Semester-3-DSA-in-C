#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char type[15];
    printf("Available data structures : \n1. Array\n2. Linked List\n3. Tree\n4. Graph\n\n");
    printf("Enter the data structure : ");
    fgets(type, sizeof(type), stdin);

    for(int i=0; type[i] != '\0'; i++){
        type[i] = tolower(type[i]);
    }
    type[strcspn(type, "\n")] = '\0';

    if(strcmp(type, "array") == 0){
        printf("Non-Primitive and Linear");
    }
    else if(strcmp(type, "linked list") == 0){
        printf("Non-Primitive and Linear");
    }
    else if(strcmp(type, "tree") == 0){
        printf("Non-Primitive and Non-Linear");
    }
    else if(strcmp(type, "graph") == 0){
        printf("Non-Primitive and Non-Linear");
    }
    else{
        printf("Please make sure to enter a valid data structure");
    }
}