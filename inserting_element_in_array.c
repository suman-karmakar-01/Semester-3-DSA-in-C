#include<stdio.h>

int insert(int array[], int size, int target, int location){
    for(int i=size; i>=location; i--){
        array[i] = array[i-1];
    }
    array[location] = target;
}

int main(){
    int array[10] = {10,30,40,50,60,80};
    int current_size = 6;
    int target;
    int pos;
    printf("Enter the number you wanna insert : ");
    scanf("%d", &target);
    printf("Enter the position where you wanna insert : ");
    scanf("%d", &pos);

    insert(array, current_size, target, pos);

    current_size++;
    for(int i=0; i<current_size; i++){
        printf("%d", array[i]);
        if(i>=0 && i<current_size-1){
            printf(", ");
        }
    }
}