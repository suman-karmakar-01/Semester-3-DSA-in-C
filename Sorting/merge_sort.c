#include<stdio.h>

void merge(int nums[], int low, int mid,int high){
	int numsSize1 = mid-low+1;
	int numsSize2 = high-mid;
	int nums1[numsSize1], nums2[numsSize2];
	 
	for(int i=0; i<numsSize1; i++)
		nums1[i] = nums[low+i];
	for(int j=0; j<numsSize2; j++)
		nums2[j] = nums[mid+j+1];
	int i=0 ,j=0 ,k=low;
	while(i<numsSize1 && j<numsSize2){
		if(nums1[i] <= nums2[j]){
			nums[k] = nums1[i];
			i++;
		}
		else{
			nums[k] = nums2[j];
			j++;
		}
		k++;
	}
	while(i<numsSize1){
		nums[k] = nums1[i];
		i++;
		k++;
	}
	while(j<numsSize2){
		nums[k] = nums2[j];
		j++;
		k++;
	}
}

void mergeSort(int nums[], int low, int high){
	if(low<high){
		int mid = low + (high-low)/2;
		mergeSort(nums, low, mid);
		mergeSort(nums, mid+1, high);
		merge(nums, low, mid, high);
	}
}

int main(){
	int nums[] = {4,7,1,9,8,5,3,2};
	int numsSize = sizeof(nums)/sizeof(*nums);
	mergeSort(nums, 0, numsSize-1);
	
	for(int i=0; i<numsSize; i++){
		printf("%d", nums[i]);
		if(i<numsSize-1) printf(", ");
	}
}