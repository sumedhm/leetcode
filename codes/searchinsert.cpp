#include <iostream>
#include <vector>

using namespace std;

int searchInsert_(vector<int> nums, int left, int right, int target){
	//cout << left << "," << right << endl;
	if(left<0) return 0;
	if(left>=right){
		if(nums[left]==target) return left;
		if(nums[right]==target) return right;
		if(nums[right]>target) return right;
		else return right+1;
	}
	if(nums[left]==target) return left;
	if(nums[right]==target) return right;
	int mid = (left+right)/2;
	//cout << "-" << mid << endl;
	if(nums[mid]==target) return mid;
	else if(nums[mid]>target) return searchInsert_(nums, left+1, mid-1, target);
	else return searchInsert_(nums, mid+1, right-1, target);
}

int searchInsert(vector<int>& nums, int target) {
		if(nums[0]>target) return 0;
		if(nums[nums.size()-1]<target) return nums.size();
        return searchInsert_(nums, 0, nums.size()-1, target);
}

int main(){

	int arr[] = {1,3,5,6};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	cout << searchInsert(nums,4) << endl;
	return 0;
}