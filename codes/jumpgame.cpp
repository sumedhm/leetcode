#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
        if(nums.size()==0) return true;
        int target = nums.size()-1;
        int pos = nums.size()-2;
        while(pos>=0){
        cout << pos << target << endl;
        	if(pos+nums[pos]>=target) target = pos;
        	pos--;
        }
        if(target==0) return true;
        return false;
}

int main(){
	int arr[] = {2,3,1,1,4};
	vector<int> nums(arr,arr+sizeof(arr)/sizeof(int));
	cout << canJump(nums) << endl;
	return 0;
}