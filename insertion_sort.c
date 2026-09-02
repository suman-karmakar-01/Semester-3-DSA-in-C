#include<stdio.h>

void insertionSort(int arr[], int size){
    for(int i=1; i<size; i++){
    	int key = arr[i];
    	int j = i-1;
    	while(j>=0 && key<arr[j]){
    		arr[j+1] = arr[j];
        	j--;
		}
		arr[j+1] = key;
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
    int array[] = {7,2,6,8,9,1,5,4,3};
    int size = sizeof(array)/sizeof(*array);
    insertionSort(array, size);
    for(int i=0; i<size; i++){
        printf("%d", array[i]);
        if(i<size-1){
            printf(", ");
        }
    }
}