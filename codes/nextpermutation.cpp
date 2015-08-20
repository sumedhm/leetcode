#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& nums, int left, int right){
	int pivot = nums[(left+right)/2];
	int temp;
	int i=left, j=right;
	while(i<=j){
		while(nums[i]<pivot) i++;
		while(nums[j]>pivot) j--;
		if(i<=j){
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			i++; j--;
		}
	}
	if(j>left) quickSort(nums, left, j);
	if(i<right) quickSort(nums, i, right);
	return;
}

void reverse(vector<int>& nums, int left, int right){
	int temp;
	while(left<right){
		temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
		left++; right--;
	}
	return;
}

void nextPermutation(vector<int>& nums) {
		if(nums.size()<=1) return;
		int swap = nums.size()-1, index = -1;
		//cout << swap << endl;
        for(int i=nums.size()-1;i>0;i--){
        	if(nums[i]>nums[i-1]){
        		swap = i-1;
        		break;
        	}
        }
        for(int i=swap;i<nums.size();i++){
        	if(nums[i]>nums[swap]){
        		index = i;
        	}
        }
        if(index==-1){
        	quickSort(nums,0,nums.size()-1);
        	return;
        };
        int temp = nums[swap];
        nums[swap] = nums[index];
        nums[index] = temp;
        reverse(nums,swap+1,nums.size()-1);
        return;
}

int main(){

	int arr[] = {1,3,2};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	nextPermutation(nums);
	for(int i=0;i<nums.size();i++) cout << nums[i] << endl;
	return 0;
}