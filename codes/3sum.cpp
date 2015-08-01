#include <iostream>
#include <vector>
#include <string>

using namespace std;

void quickSort(vector<int>& nums, int left, int right){
	int pivot = nums[(left+right)/2];
	int temp, i=left, j=right;
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

void twoSum(vector<vector<int> >& ans, vector<int> nums, int index){
	int target = -nums[index];
	int i = index+1, j=nums.size()-1;
	while(i<j){
		int sum = (nums[i]+nums[j]);
		if(sum==target){
			int arr[] = {nums[index], nums[i], nums[j]};
			vector<int> temp(arr, arr+sizeof(arr)/sizeof(int));
			ans.push_back(temp);
		}
		if(sum>target){
			j--;
			while(j<nums.size() && nums[j]==nums[j+1]) j--;
		}
		else{
			i++;
			while(i>=0 && nums[i]==nums[i-1]) i++;	
		}		
	}
	return;
}

vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > ans;
	if(nums.size()==0) return ans;
	quickSort(nums, 0, nums.size()-1);
	for(int i=0;i<nums.size();i++){
		if(i>0 && nums[i]==nums[i-1]) continue;
		twoSum(ans, nums, i);
	}
    return ans;
}

int main(){
	int arr[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	vector<int> set(arr, arr+sizeof(arr)/sizeof(int));
	vector<vector<int> > ans = threeSum(set);
	cout << endl;
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout << ans[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}