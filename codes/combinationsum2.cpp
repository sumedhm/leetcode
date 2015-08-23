#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& nums, int left, int right){
	int pivot = nums[(left+right)/2];
	int i = left, j = right;
	int temp;
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

void dfs(vector<int>& candidates, vector<vector<int> >& ans, vector<int>& tmp, int target, int i){
	if(target<0) return;
	if(target==0){
		ans.push_back(tmp);
		return;
	} else {
		while(i<candidates.size()){
			tmp.push_back(candidates[i]);
			dfs(candidates, ans, tmp, target-candidates[i], i);
			i++;
			tmp.pop_back();
		}
	}
	return;
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
		if(candidates.size()==0) return ans;
        vector<int> tmp;
        quickSort(candidates, 0, candidates.size()-1);
        dfs(candidates, ans, tmp, target, 0);
        return ans;
} 

int main(){
	int arr[] = {1,2,3,4,5,6,7};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	vector<vector<int> > ans = combinationSum(nums, 12);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}