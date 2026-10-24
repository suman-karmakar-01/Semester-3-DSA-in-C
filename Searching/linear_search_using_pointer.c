#include<stdio.h>

void search(int arr[], int size, int target){
    int found = 0;
    for(int i=0; i<size; i++){
        if(target == *(arr + i)){
            printf("%d was found at arr[%d]", target, i);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("%d was not found!", target);
    }
}

int main(){
    int x;
    int arr[] = {10,15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70};
    int size = sizeof(arr)/ sizeof(*arr);
    printf("Enter the number you are searching for : ");
    scanf("%d", &x);
    search(arr, size, x);
}