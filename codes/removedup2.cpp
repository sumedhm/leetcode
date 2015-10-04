#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	if(nums.size()<=1) return nums.size();
	int count = 1;
    for(int i=1;i<nums.size();i++){
    	if(nums[i]==nums[i-1]) count++;
    	else count = 1;
    	if(count>2){
    		nums.erase(nums.begin()+i);
    		i--;
    	}
    }
    for(int i=0;i<nums.size();i++) cout << nums[i] << " ";
    cout << endl;
	return nums.size();
}

int main(){
	int arr[] = {1,1,1,2,2,3,4,4,4,4,4,5,5};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	cout << removeDuplicates(nums) << endl;
	return 0;
}