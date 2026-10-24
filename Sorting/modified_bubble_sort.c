#include<stdio.h>

void bubbleSort(int arr[], int size){
	int swap_counter=0;
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap_counter++;
            }
        }
        if(!swap_counter){
        	break;
		}
        for(int j=0; j<size; j++){
            printf("%d", arr[j]);
            if(j<size-1){
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main(){
    //int array[] = {7,2,6,8,9,1,5,4,3};
    int array[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(array)/sizeof(array[0]);
    bubbleSort(array, size);
    for(int i=0; i<size; i++){
        printf("%d", array[i]);
        if(i<size-1){
            printf(", ");
        }
    }
}