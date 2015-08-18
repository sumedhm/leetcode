#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	int count = 1;
	for(int i=1;i<nums.size();i++){
		if(nums[i]!=nums[i-1]) count++;
		else{
			nums.erase(nums.begin()+i);
			i--;
		}
	}
	return count;
}

int main(){
	int arr[] = {1,2,2,3,3,3,3,3,3,5,5,6,7};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	cout << removeDuplicates(nums) << endl;
	return 0;
}