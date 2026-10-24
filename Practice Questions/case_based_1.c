//Take an array of 9 elements, try searching 1 element if its present right in the middle, return the index and then sort the left side array in decending order using the sorting that will work as the worst case scenario. And sort the right side using that algorithm which will work the best in descending. If it is not found in the middle, insert that element in the middle and then sort it in asc which will work best for this case.

#include<stdio.h>
#include<stdlib.h>

void merge(int nums[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = nums[left + i];
    for (j = 0; j < n2; j++)
        R[j] = nums[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            nums[k] = L[i];
            i++;
        } else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        nums[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        nums[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int nums[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }
}

void bubbleSort(int nums[], int numsSize){
    for(int i=0; i<numsSize-1; i++){
        for(int j=0; j<numsSize-i-1; j++){
            if(nums[j] < nums[j+1]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}

void insertionSort(int nums[], int numsSize){
    for(int i=1; i<numsSize; i++){
        int key = nums[i];
        int j = i-1;
        while(j>=0 && key<nums[j]){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = key;
    }
}

int binarySearch(int nums[], int low, int high, int target){
    int mid = low + (high-low)/2;
    if(target == nums[mid]){
        bubbleSort(nums, mid);
        mergeSort(nums, mid+1, high);
        return mid;
    }
    else{
        nums[mid] = target;
        insertionSort(nums, high+1);
        return mid;
    }
}

int main(){
    int nums[] = {2,4,6,8,10,12,14,16,18};
    int numsSize = sizeof(nums)/sizeof(*nums);
    int target = 21;
    int mid = binarySearch(nums, 0, numsSize-1, target);

    printf("Middle Index : %d", mid);
    printf("\n");
    for(int i=0; i<numsSize; i++){
        printf("%d ", nums[i]);
    }
}
