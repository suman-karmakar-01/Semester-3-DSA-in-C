#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&arr[i], &arr[min_idx]);
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