#include <iostream>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
		int size = nums.size();
		int i=0,j=size-1;
		int temp;
		while(i<j){
			while(nums[i]>0) i++;
			while(nums[j]<=0) j--;
			if(i<j){
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
				i++; j--;
			}
		}
		for(j=0;j<size;j++){
			if(nums[j]<=0) break;
			
		}
		int index;
		for(i=0;i<j;i++){
			index = nums[i];
			if(index<0) index = -index;
			if(index<=size){
				if(nums[index-1]>0)
					nums[index-1] = -nums[index-1];
			}
		}
		for(i=0;i<j;i++){
			if(nums[i]>0) break;
		}
		return i+1;
}

int main(){

	int arr[] = {2,1};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	cout << firstMissingPositive(nums) << endl;
	cout << "---------------------" << endl;
	for(int i=0;i<nums.size();i++){
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}