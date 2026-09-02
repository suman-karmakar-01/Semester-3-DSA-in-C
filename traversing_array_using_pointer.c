#include<stdio.h>

void display(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d", *(arr + i));
        if(i<size-1){
            printf(", ");
        }
    }
}

int main(){
    int arr[] = {10,15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70};
    int size = sizeof(arr)/ sizeof(*arr);
    display(arr, size);
}