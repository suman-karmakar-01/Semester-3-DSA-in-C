#include<stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;	
}

int partition(int nums[], int low, int high){
	int pivot = nums[high];
	int i = (low - 1);	
	for(int j=low; j<high; j++){
		if(nums[j]<=pivot){
			i++;
			swap(&nums[i], &nums[j]);
		}
	}
	swap(&nums[i+1], &nums[high]);
	return (i+1);
}

void quickSort(int nums[], int low, int high){
	if(low<high){
		int pivot = partition(nums, low, high);
		quickSort(nums, low, pivot-1);
		quickSort(nums, pivot+1, high);
	}
}

int main(){
	int nums[] = {4,5,7,9,1,3,8,2,6};
	int numsSize = sizeof(nums)/sizeof(*nums);
	quickSort(nums, 0, numsSize-1);
	
	for(int i=0; i<numsSize; i++){
		printf("%d", nums[i]);
		if(i<numsSize-1) printf(", ");
	}
}