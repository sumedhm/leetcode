#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b){
	return (a>b)? a : b;
}

int jump(vector<int>& nums){
	if(nums.size()<2) return 0;
	int i = 0;
	int m = 0;
	int jumps=0, tmp = 0;
	while(i<nums.size()){
		m = max(m, nums[i]+i);
		jumps++;
		if(m>=nums.size()-1) return jumps;
		for(int j=i+1;j<=m;j++){
			if(j+nums[j]>tmp){
				tmp = j+nums[j];
				i = j;
			}
		}
	}
	return jumps;
}

int main(){
	int arr[] = {2,3,1,1,4};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	cout << jump(nums) << endl;
	return 0;
}