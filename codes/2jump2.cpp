#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b){
	return (a<b)? a : b;
}

int jump_num(vector<int> nums, int i, int jumps){
	// cout << i << jumps << endl;
	if(i>=nums.size()) return jumps*10;
	if(i==nums.size()-1) return jumps;
	if(nums[i]==0) return jump_num(nums, i+1, jumps+1);
	else return min(jump_num(nums, i+1, jumps+1), jump_num(nums, i+nums[i], jumps+1));
}

int jump(vector<int>& nums){
	return jump_num(nums, 0, 0);
}

int main(){
	int arr[] = {7,8,4,2,0,6,4,1,8,7,1,7,4,1,4,1,2,8,2,7,3,7,8,2,4,4,5,3,5,6,8,5,4,4,7,4,3,4,8,1,1,9,0,8,2};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	cout << jump(nums) << endl;
	return 0;
}