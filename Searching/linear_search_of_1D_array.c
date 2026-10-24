#include<stdio.h>

void search(int array[], int size, int target){
    int found = 0;
    for(int i=0; i<size; i++){
        if(target == array[i]){
            printf("%d was found at : array[%d]", target, i);
            found = 1; 
            break;
        }
    }
    if(!found){
        printf("%d was not found in the array", target);
    }
}

int main(){
    int array[] = {15,25,35,45,55,65,75,85,95};
    int size = sizeof(array)/sizeof(array[0]);
    int target;
    printf("Enter the element you wanna search for : ");
    scanf("%d", &target);

    search(array, size, target);
}