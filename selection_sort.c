#include<stdio.h>

void selectionSort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size; j++){
            printf("%d", arr[j]);
            if(j<size-1){
                printf(", ");
            }
        }
        printf("\n");
    	int min_index = i;
        for(int j=i+1; j<size; j++){
            if(arr[min_index]>arr[j]){
                int temp = arr[j];
                arr[j] = arr[min_index];
                arr[min_index] = temp;
            }
        }
    }
}

int main(){
    int array[] = {7,2,6,8,9,1,5,4,3};
    int size = sizeof(array)/sizeof(array[0]);
    selectionSort(array, size);
    for(int i=0; i<size; i++){
        printf("%d", array[i]);
        if(i<size-1){
            printf(", ");
        }
    }
}