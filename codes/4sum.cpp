#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<int>& nums, int left, int right){
	int pivot = nums[(left+right)/2];
	int i=left,j=right;
	while(i<=j){
		while(nums[i]<pivot) i++;
		while(nums[j]>pivot) j--;
		if(i<=j){
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			i++; j--;
		}
	}
	if(j>left) quickSort(nums,left,j);
	if(i<right) quickSort(nums,i,right);
	return;
}

bool exists(vector<vector<int> > ans, vector<int> temp){
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			if(ans[i][j]!=temp[j]){
				break;
			}
			if(j==3) return true;
		}
	}
	return false;
}

void twoSum(vector<vector<int> >& ans, vector<int> nums, int target, int index1, int index2){
	int i=index2+1, j=nums.size()-1;
	int sum;
	while(i<j){
		sum = nums[i]+nums[j];
		if(sum==target){
			int arr[] = {nums[index1],nums[index2],nums[i],nums[j]};
			vector<int> temp(arr, arr+sizeof(arr)/sizeof(int));
			if(!exists(ans,temp)){
				ans.push_back(temp);
			}
		}
		if(sum>target){
			j--;
			while(j<nums.size()-1 && nums[j]==nums[j+1]) j--;
		} else {
			i++;
			while(i>0 && nums[i]==nums[i-1]) i++;
		}		
	}
	return;
}

void threeSum(vector<vector<int> >& ans, vector<int> nums, int target, int index){
	for(int i=index+1;i<nums.size();i++){
		if(i>0 && nums[i]==nums[i-1]) continue;
		twoSum(ans, nums, target-nums[i], index, i);
	}
	return;
}

vector<vector<int> > fourSum(vector<int>& nums, int target) {
    vector<vector<int> > ans;
    if(nums.size()<4) return ans;
    quickSort(nums, 0, nums.size()-1);
    for(int i=0;i<nums.size();i++){
    	cout << nums[i] << "-";
    }
    cout << endl;
    for(int i=0;i<nums.size();i++){
    	if(i>0 && nums[i]==nums[i-1]) continue;
    	threeSum(ans,nums,target-nums[i],i);
    }
    return ans;
}

int main(){

	int arr[] = {-3,-2,-1,0,0,1,2,3};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	vector<vector<int> > ans = fourSum(nums, 0);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout << ans[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}