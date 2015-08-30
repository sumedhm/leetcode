#include <iostream>
#include <vector>

using namespace std;

void permute(vector<vector<int> >& ans, vector<int>&nums, int left, int right){
	if(left>right) return;
	if(left==right){
		ans.push_back(nums);
		return;
	}
	int temp;
	for(int i=left;i<=right;i++){
		if(nums[i]==nums[left] && i!=left){
			continue;
		}
		temp = nums[left];
		nums[left] = nums[i];
		nums[i] = temp;
		permute(ans, nums, left+1, right);
		temp = nums[left];
		nums[left] = nums[i];
		nums[i] = temp;
	}
	return;
}

vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > ans;
        if(nums.size()<1) return ans;
        // ans.push_back(nums);
        permute(ans, nums, 0, nums.size()-1);
        return ans;
}

int main(){
	int arr[] = {3,3,0,0,2,3,2};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	vector<vector<int> > ans = permuteUnique(nums);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}