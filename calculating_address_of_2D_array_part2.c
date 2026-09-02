#include<stdio.h>
#include<ctype.h>

void options(){
    printf("-----------------------\n");
    printf("|    1. Row Major     |\n");
    printf("|    2. Column Major  |\n");
    printf("-----------------------\n");
}

void rowmajor(int arr[3][4], int B, int W, int I, int LR, int N, int J, int LC){
    int result = B+W*((I-LR)*N + (J-LC));
    printf("Address of arr[%d][%d] = %d is : %d\n", I-LR,J-LC,arr[I-LR][J-LC], result);
}

void columnmajor(int arr[3][4], int B, int W, int I, int LR, int M, int J, int LC){
    int result = B+W*((I-LR)*M + (J-LC));
    printf("Address of arr[%d][%d] = %d is : %d\n", I-LR,J-LC,arr[I-LR][J-LC], result);
}

int main(){
    int arr[3][4] = {{1,2,3,4},{5,6,7,11},{92,93,94,99}};
    int choice,W,I,J,LC,LR,M,N;
    int *B = &arr[0][0];
    W = sizeof(int);
    N = sizeof(arr[0])/sizeof(arr[0][0]);
    M = sizeof(arr)/sizeof(arr[0]);
    char repeat = 'y';
    do{
        options();
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the base address : ");
                scanf("%d", &B);
                printf("Enter the row number you are looking for : ");
                scanf("%d", &I);
                printf("Enter the column number you are looking for : ");
                scanf("%d", &J);
                printf("Enter the lowest row index : ");
                scanf("%d", &LR);
                printf("Enter the lowest column index : ");
                scanf("%d", &LC);
                rowmajor(arr, B, W, I, LR, N, J, LC);
                break;
            case 2:
                printf("Enter the base address : ");
                scanf("%d", &B);
                printf("Enter the row number you are looking for : ");
                scanf("%d", &I);
                printf("Enter the column number you are looking for : ");
                scanf("%d", &J);
                printf("Enter the lowest row index : ");
                scanf("%d", &LR);
                printf("Enter the lowest column index : ");
                scanf("%d", &LC);
                columnmajor(arr, B, W, I, LR, M, J, LC);
                break;
            default : 
                printf("Please enter a valid choice!");
        }

        printf("Do you wanna continue? (Y/N) : ");
        scanf(" %c", &repeat);
        repeat = tolower(repeat);
    }while(repeat == 'y');
    printf("------------------\n");
    printf("|   Thank You    |\n");
    printf("------------------\n");
}