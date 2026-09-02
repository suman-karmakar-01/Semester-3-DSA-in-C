#include<stdio.h>

void access(int arr[], int x, int size){
    if(x < size && x>=0){
        for(int i=0; i<size; i++){
            if(*(arr + x) == *(arr + i)){
                printf("arr[%d] = %d", i, *(arr + i));
                break;
            }
        }
    }
    else{
        printf("Please enter a valid index!");
    }
}

int main(){
    int arr[]={10,20,30,40,50,60,70,80,90};
    int size = sizeof(arr)/sizeof(*arr);
    int pos;
    printf("Enter the index number : ");
    scanf("%d", &pos);
    access(arr, pos, size);
}