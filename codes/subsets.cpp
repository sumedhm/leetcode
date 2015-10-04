#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& nums, int left, int right){
	int i = left, j = right, tmp, pivot = nums[(left+right)/2];
	while(i<=j){
		while(nums[i]<pivot) i++;
		while(nums[j]>pivot) j--;
		if(i<=j){
			tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
			i++; j--;
		}
	}
	if(j>left) quickSort(nums, left, j);
	if(i<right) quickSort(nums, i, right);
	return;
}

vector<vector<int> > subsets(vector<int>& nums) {
	vector<vector<int> > ans;
	vector<int> tmp;
	ans.push_back(tmp);
	if(nums.size()==0) return ans;
	quickSort(nums,0,nums.size()-1);
	int n;
	for(int i=0;i<nums.size();i++){
		n = ans.size();
		for(int j=0;j<n;j++){
			tmp = ans[j];
			tmp.push_back(nums[i]);
			ans.push_back(tmp);
		}
	}
	return ans;
}

int main(){
	int arr[] = {4,1,0};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	vector<vector<int> > ans = subsets(nums);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}