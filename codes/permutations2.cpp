#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& nums, int left, int right){
	int i = left, j = right;
	int temp;
	int pivot = nums[(left+right)/2];
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
	if(i<right) quickSort(nums, i, right);
	if(j>left) quickSort(nums, left, j);
	return;
}

void reverse(vector<int>& nums, int i, int j){
	int temp;	
	while(i<j){
		temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
		i++; j--;
	}
	return;
}

int nextPermutation(vector<int>& nums, vector<vector<int> >& ans){
		int i=nums.size()-1;
		while(i>0){
			if(nums[i]>nums[i-1]) break;
			i--;
		}
		if(i==0) return -1;
		int index;
		for(int j=i;j<nums.size();j++){
			if(nums[j]>nums[i-1]) index = j;
		}
		cout << i << index << endl;
		int temp = nums[i-1];
		nums[i-1] = nums[index];
		nums[index] = temp;
		reverse(nums, i, nums.size()-1);
		ans.push_back(nums);
		return 0;
}

vector<vector<int> > permuteUnique(vector<int>& nums) {
		vector<vector<int> > ans;
		if(nums.size()<1) return ans;
		quickSort(nums,0,nums.size()-1);
		ans.push_back(nums);
        int res = 0;
        while(res!=-1){
        	res = nextPermutation(nums, ans);
        }
        return ans;
}

int main(){
	int arr[] = {1,2,1,1,2};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	vector<vector<int> > ans;
	ans = permute(nums);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}