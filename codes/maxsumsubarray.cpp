#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
        int sum = nums[0], cur = nums[0];
        for(int i=1;i<nums.size();i++){
        	if(cur+nums[i] > nums[i]){
        		cur = cur + nums[i];
        	} else {
        		cur = nums[i];
        	}
        	if(sum<cur) sum = cur;
        }
        return sum;
}

int main(){
	int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	cout << maxSubArray(nums) << endl;
	return 0;
}