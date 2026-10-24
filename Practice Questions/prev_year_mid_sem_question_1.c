//Take an array of 10 elements randomly unsorted, implement the sorting which checks two adjacent elements and swaps them if needed and perform this sorting for 1 external loops iteration, then take that intermediate array and pass it to a sorting function which performs worst when the array is sorted

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

void bubbleSort(int nums[], int numsSize){
	int count=0;
	for(int i=0; i<numsSize-1; i++){
		for(int j=0; j<numsSize-i-1; j++){
			if(nums[j+1]<nums[j]){
				swap(&nums[j+1], &nums[j]);
			}
		}
		count++;
		if(count==1){
			quickSort(nums, 0, numsSize);
			return;
		}
	}
}

int main(){
	int nums[] = {4,5,7,9,1,3,8,2,6};
	int numsSize = sizeof(nums)/sizeof(*nums);
	bubbleSort(nums, numsSize);
	
	for(int i=0; i<numsSize; i++){
		printf("%d", nums[i]);
		if(i<numsSize-1) printf(", ");
	}
}
