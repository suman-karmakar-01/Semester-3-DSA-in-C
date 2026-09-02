#include<stdio.h>

int delete(int array[], int pos, int size){
    for(int i=pos; i<size; i++){
        array[i] = array[i+1];
    }
}

int main(){
    int array[] = {10,20,30,40,45,50,60};
    int current_size = 7;
    int target_pos;
    printf("Enter the position of element you wanna delete : ");
    scanf("%d", &target_pos);

    delete(array, target_pos, current_size);
    
    current_size--;
    for(int i=0; i<current_size; i++){
        printf("%d", array[i]);
        if(i>=0 && i< current_size-1){
            printf(", ");
        }
    }
}