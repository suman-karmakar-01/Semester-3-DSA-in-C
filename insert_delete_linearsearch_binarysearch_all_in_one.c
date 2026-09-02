#include<stdio.h>
#include<string.h>
#include<ctype.h>

void options(){
    printf("-----------------------------------------\n");
    printf("|  1. Display the entire array          |\n");
    printf("|  2. Insert an element in an array     |\n");
    printf("|  3. Delete an element from an array   |\n");
    printf("|  4. Linear searching from 1D array    |\n");
    printf("|  5. Binary searching using iteration  |\n");
    printf("|  6. Binary searching using recurtion  |\n");
    printf("-----------------------------------------\n");
}

int insert(int array[], int size, int target, int location){
    for(int i=size; i>=location; i--){
        array[i] = array[i-1];
    }
    array[location] = target;
}

int delete(int array[], int pos, int size){
    for(int i=pos; i<size; i++){
        array[i] = array[i+1];
    }
}

void search(int array[], int size, int target){
    int found = 0;
    for(int i=0; i<size; i++){
        if(target == array[i]){
            printf("%d was found at : array[%d]", target, i);
            found = 1; 
            break;
        }
    }
    if(!found){
        printf("%d was not found in the array", target);
    }
}

int binary_search1(int array[], int lower_index, int higher_index, int target){
    while(lower_index<=higher_index){
        int middle = lower_index + (higher_index - lower_index)/2;
        if(target == array[middle]){
            return middle;
        }
        if(target > array[middle]){
            lower_index = middle+1;
        }
        else{
            higher_index = middle-1;
        }
    }
    return -1;
}

int binary_search2(int array[], int lower_index, int higher_index, int target){
    if(lower_index <= higher_index){
        int middle = lower_index + (higher_index - lower_index)/2;
        if(target == array[middle]){
            return middle;
        }
        if(target > array[middle]){
            return binary_search2(array, middle+1, higher_index, target);
        }
        else{
            return binary_search2(array, lower_index, middle - 1, target);
        }
    }
    return -1;
}

int main(){
    char repeat = 'y';
    int array[] = {10,15,20,25,30,35,40,45,50,55,60};
    do{
        options();

        int current_size = sizeof(array)/ sizeof(array[0]);
        int target;
        int pos;
        int result;

        int choice;
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                //Display
                for(int i=0; i<current_size; i++){
                    printf("%d", array[i]);
                    if(i>=0 && i<current_size-1){
                        printf(", ");
                    }
                }
                break;
            case 2:
                printf("Enter the value you wanna insert : ");
                scanf("%d", &target);
                printf("Enter the position where you wanna insert : ");
                scanf("%d", &pos);

                insert(array, current_size, target, pos);
                current_size++;

                //Display
                for(int i=0; i<current_size; i++){
                    printf("%d", array[i]);
                    if(i>=0 && i<current_size-1){
                        printf(", ");
                    }
                }
                break;
            case 3:
                printf("Enter the position of element you wanna delete : ");
                scanf("%d", &pos);

                delete(array, pos, current_size);
                current_size--;

                //Display
                for(int i=0; i<current_size; i++){
                    printf("%d", array[i]);
                    if(i>=0 && i< current_size-1){
                        printf(", ");
                    }
                }
                break;
            case 4:
                printf("Enter the element you wanna search for : ");
                scanf("%d", &target);

                search(array, current_size, target);
                break;
            case 5:{
                    printf("Enter the element you wanna search for : ");
                    scanf("%d", &target);

                    int result = binary_search1(array, 0, current_size-1, target);
        
                    if(result != -1){
                        printf("%d was found at : array[%d]", target, result);
                    }
                    else{
                        printf("%d was not found in the array!", target);
                    }
                    break;
                }
            case 6:{
                    printf("Enter the element you wanna search for : ");
                    scanf("%d", &target);

                    int result = binary_search2(array, 0, current_size-1, target);
        
                    if(result != -1){
                        printf("%d was found at : array[%d]", target, result);
                    }
                    else{
                        printf("%d was not found in the array!", target);
                    }
                    break;
                }
            default:
                printf("Please enter a valid option!");
        }

        //Repeatation
        printf("\n\nDo you want to do it again? (Y/N) : ");
        scanf(" %c", &repeat);
        repeat = tolower(repeat);
    }while(repeat == 'y');
    printf("---------------------\n");
    printf("|     Thank You     |\n");
    printf("---------------------");
}