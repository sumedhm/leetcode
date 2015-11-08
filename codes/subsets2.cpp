#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > subsetsWithDup(vector<int>& nums) {
	vector<vector<int> > res;
	int size = nums.size();
	vector<int> tmp;
	res.push_back(tmp);
	if(size==0) return res;
	sort(nums.begin(),nums.end());
	int last = 1;
	tmp.push_back(nums[0]);
	res.push_back(tmp);
	int newSize;
	for(int i=1;i<size;i++){
		tmp.clear();
		newSize = res.size();
		if(nums[i]==nums[i-1]){
			//
		} else {
			last = 0;
		}
		for(int j=last;j<newSize;j++){
			tmp = res[j];
			tmp.push_back(nums[i]);
			res.push_back(tmp);
		}
		last = newSize;
	}
	return res;
}

int main(){
	int arr[] = {4,1,0};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	vector<vector<int> > ans = subsetsWithDup(nums);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout << ans[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}