#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void quickSort(vector<int>& nums, int left, int right){
	int pivot = nums[(left+right)/2];
	int temp, i=left, j=right;
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

int twoSumClosest(vector<int> nums, int index, int target){
	int i = index+1, j=nums.size()-1;
	int closest=(nums[index]+nums[i]+nums[j]);
	while(i<j){
		//cout << nums[index] << "," << nums[i] << "," << nums[j] << endl;
		int sum = (nums[index]+nums[i]+nums[j]);
		if(sum==target){
			return target;
		}
		if(abs(target-sum)<abs(target-closest)) closest = sum;
		//cout << closest << endl;
		//else return closest;
		if(sum>target){
			j--;
			while(j<nums.size() && nums[j]==nums[j+1]) j--;
		}
		else{
			i++;
			while(i>=0 && nums[i]==nums[i-1]) i++;	
		}		
	}
	return closest;
}

int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size()==0) return 0;
	quickSort(nums, 0, nums.size()-1);
	int closest=nums[0]+nums[1]+nums[2];
	for(int i=0;i<nums.size()-2;i++){
		if(i>0 && nums[i]==nums[i-1]) continue;
		int temp = twoSumClosest(nums, i, target);
		//cout << temp << endl;
		if(temp==target) return target;
		if(abs(target-temp)<abs(target-closest)) closest = temp;
	}
    return closest;
}

int main(){
	int arr[] = {0,-4,1,-5};
	vector<int> set(arr, arr+sizeof(arr)/sizeof(int));
	cout << threeSumClosest(set,0) << endl;
	
	return 0;
}