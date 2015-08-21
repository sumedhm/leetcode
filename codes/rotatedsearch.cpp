#include <iostream>
#include <vector>

using namespace std;

int searchrotated(vector<int> nums, int left, int right, int target){
	if(left>right) return -1;
	if(nums[left]==target) return left;
	if(nums[right]==target) return right;
	int mid = (left+right)/2;
	if(nums[mid]==target) return mid;
	else {
		int inleft=-1, inright=-1;
		if((nums[left]>target && nums[mid]<target) || (nums[left]<target && nums[mid]>target)) inleft = searchrotated(nums, left+1, mid-1, target);
		if((nums[right]>target && nums[mid]<target) || (nums[right]<target && nums[mid]>target)) inright = searchrotated(nums, mid+1, right-1, target);
		if(inleft==-1 && inright==-1){
			inleft = searchrotated(nums, left+1, mid-1, target);
			inright = searchrotated(nums, mid+1, right-1, target);
		}
		if(inleft!=-1) return inleft;
		if(inright!=-1) return inright;
	}
	return -1;
}

int search(vector<int>& nums, int target){
	return searchrotated(nums, 0, nums.size()-1, target);
}

int main(){

	int arr[] = {4,5,6,7,1,2,3};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	cout << search(nums, 8) << endl;
	return 0;
}