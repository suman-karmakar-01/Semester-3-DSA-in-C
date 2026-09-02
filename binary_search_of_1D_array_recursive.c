#include<stdio.h>

int binary_search(int array[], int lower_index, int higher_index, int target){
    if(lower_index <= higher_index){
        int middle = lower_index + (higher_index - lower_index)/2;
        if(target == array[middle]){
            return middle;
        }
        if(target > array[middle]){
            return binary_search(array, middle+1, higher_index, target);
        }
        else{
            return binary_search(array, lower_index, middle - 1, target);
        }
    }
    return -1;
}

int main(){
    int array[] = {10,15,20,25,30,35,40,45,50,55,60,65};
    int size = sizeof(array)/ sizeof(array[0]);
    int target;
    printf("Enter the element you wanna search for : ");
    scanf("%d", &target);

    int result = binary_search(array, 0, size-1, target);
    
    if(result != -1){
        printf("%d was found at : array[%d]", target, result);
    }
    else{
        printf("%d was not found in the array!", target);
    }
}