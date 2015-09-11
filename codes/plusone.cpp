#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
		int carry = 1;
        for(int i=digits.size()-1;i>=0;i--){
        	digits[i] += carry;
        	if(digits[i]>9){
        		digits[i] = digits[i] - 10;
        		carry = 1;
        	} else {
        		carry = 0;
        		break;
        	}
        }
        if(carry==1) digits.insert(digits.begin(), 1);
        return digits;
}

int main(){
	int arr[] = {9,9,9,9,9};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	nums = plusOne(nums);
	for(int i=0;i<nums.size();i++){
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}