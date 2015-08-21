#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange_(vector<int>& nums, int left, int right, int target){
	vector<int> ans(2);
	int pos;
	if(nums.size()==0 || left>right){
		ans[0] = ans[1] = -1;
	} else {
		pos = -1;
		int mid = (left+right)/2;
		if(nums[left]==target) pos = left;
		else if(nums[right]==target) pos = right;
		else if(nums[mid]==target) pos = mid;
		if(pos==-1){
			if(nums[mid]<target) return searchRange_(nums, mid+1, right-1, target);
			else return searchRange_(nums, left+1, mid-1, target);
		} else {
			int i = pos-1;
			while(i>=0 && nums[i]==target) i--;
			ans[0] = i+1; i = pos+1;
			while(i<nums.size() && nums[i]==target) i++;
			ans[1] = i-1;
		}
	}
	return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
        return searchRange_(nums, 0, nums.size()-1, target);
}

int main(){

	int arr[] = {1,2,7,7,8,8,9};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	nums = searchRange(nums, 5);
	cout << nums[0] << nums[1] << endl;
	return 0;
}