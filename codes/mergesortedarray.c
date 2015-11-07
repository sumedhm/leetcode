#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n) {
    int i=m-1,j=n-1,k=m+n-1;
    while(k>=0){
    	if(i>=0 && nums1[i]>nums2[j]){
    		nums1[k] = nums1[i];
    		i--;
    	} else if(j>=0){
			nums1[k] = nums2[j];
    		j--;
    	} else {
    		nums1[k] = nums1[i];
    		i--;
    	}
    	k--;
    }
    return;
}

int main(){
	int arr1[] = {1,3,5,7,9,0,0,0,0,0};
	int arr2[] = {2,4,5,6,8};
	merge(arr1,5,arr2,5);
	int i=0;
	for(i=0;i<10;i++) printf("%d ", arr1[i]);
	printf("\n");
	return 0;
}