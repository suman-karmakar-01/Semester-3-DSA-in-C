#include<stdio.h>

void access1D(int array1D[], int find){
    int found=0;
    for(int i=0; i<6; i++){
        if(find == array1D[i]){
            printf("%d found at : array1D[%d]\n", find, i);
            found=1;
            break;
        }
    }
    if(!found){
        printf("%d was not found in the array1D\n", find);
    }
}

void access2D(int array2D[][3], int find){
    int found=0;
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            if(find == array2D[i][j]){
                printf("%d found at : array2D[%d][%d]\n", find, i, j);
                found=1;
                break;
            }
        }
    }
    if(!found){
        printf("%d was not found in the array2D\n", find);
    }
}

int main(){
    int array1D[6] = {10, 35, 20, 40, 50, 60};
    int array2D[2][3] = {{10,30,50},{20,40,60}};

    int find;
    printf("Enter your number : ");
    scanf("%d", &find);
    
    access1D(array1D, find);
    access2D(array2D, find);

    //Traversing 1D array
    printf("\nTraversing 1D array : \n");
    for(int i=0; i<6; i++){
        printf("%d", array1D[i]);
        if(i>=0 && i<5){
            printf(", ");
        }
    }

    //Traversing 2D array
    printf("\n\nTraversing 2D array : \n");
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            printf("%d", array2D[i][j]);
            if(j>=0 && j<2){
                printf(", ");
            }
        }
        printf("\n");
    }
}