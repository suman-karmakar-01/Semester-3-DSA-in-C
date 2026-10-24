#include<stdio.h>

void display(int arr[], int size){
	for(int i=0; i<size; i++){
        printf("%d", arr[i]);
        if(i<size-1){
            printf(", ");
        }
    }
}
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int arr[], int size){
    for(int i=0; i<size/2; i++){
    	int min_index = i;
    	int max_index = i;
    	int start = i;
		int end = size-i-1;
        for(int j=start; j<=end; j++){
            if(arr[min_index]>arr[j]){
                min_index = j;
            }
            if(arr[max_index]<arr[j]){
                max_index = j;
            }
        }
        swap(&arr[min_index], &arr[start]);
        
        if(max_index == start){
            max_index = min_index;
        }
        
        swap(&arr[max_index], &arr[end]);

        display(arr, size);
        printf("\n");
    }
}

int main(){
    int array[] = {7,2,6,8,9,1,5,4,3};
    int size = sizeof(array)/sizeof(array[0]);
    selectionSort(array, size);
    display(array, size);
}