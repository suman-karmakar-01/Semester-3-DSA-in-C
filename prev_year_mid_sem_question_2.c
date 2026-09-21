#include<stdio.h>

void swap(int *a, int *b){
	int temp = *a; 
	*a = *b;
	*b = temp;
}

void insertionSort(int nums[], int numsSize){
	for(int i=1; i<numsSize; i++){
		int key = nums[i];
		int j = i-1;
		while(j>=0 &&  key<nums[j]){
			nums[j+1] = nums[j];
			j--;
		}
		nums[j+1] = key;
	}
}

void selectionSort(int nums[], int numsSize){
	for(int i=0; i<numsSize-1; i++){
		int min_index = i;
		for(int j=i+1; j<numsSize; j++){
			if(nums[j]<nums[min_index]){
				min_index = j;
			}
		}
		swap(&nums[i], &nums[min_index]);
	}
}

void merge(int nums1[], int nums2[], int nums3[],int numsSize1, int numsSize2, int numsSize3){
	
	int i=0 ,j=0 ,k=0;
	while(i<numsSize1 && j<numsSize2){
		if(nums1[i] <= nums2[j]){
			nums3[k] = nums1[i];
			i++;
		}
		else{
			nums3[k] = nums2[j];
			j++;
		}
		k++;
	}
	while(i<numsSize1){
		nums3[k] = nums1[i];
		i++;
		k++;
	}
	while(j<numsSize2){
		nums3[k] = nums2[j];
		j++;
		k++;
	}
}

int main(){
	int nums1[] = {7,2,9,4,1,8,5,3,6};
	int nums2[] = {14, 18, 11, 16, 13, 10, 17, 12, 15};
	int numsSize1 = sizeof(nums1)/sizeof(*nums1);
	int numsSize2 = sizeof(nums2)/sizeof(*nums2);
	int numsSize3 = numsSize1 + numsSize2;
	int nums3[numsSize3];
	
	selectionSort(nums1, numsSize1);
	insertionSort(nums2, numsSize2);
	merge(nums1, nums2, nums3, numsSize1, numsSize2, numsSize3);
	
	for(int i=0; i<numsSize1; i++){
		printf("%d", nums1[i]);
		if(i<numsSize1-1) printf(", ");
	}
	printf("\n");
	
	for(int i=0; i<numsSize2; i++){
		printf("%d", nums2[i]);
		if(i<numsSize2-1) printf(", ");
	}
	printf("\n");
	
	for(int i=0; i<numsSize3; i++){
		printf("%d", nums3[i]);
		if(i<numsSize3-1) printf(", ");
	}
}