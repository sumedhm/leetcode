#include <iostream>
#include <vector>

using namespace std;

int maximum(int a, int b){
	return ((a>b)?a:b);
}

int largestArea(vector<int> height, int left, int right){
	if(left<0 || right>=height.size()) return -1;
	if(left>right) return -1;
	else if(left==right) return height[left];
	int min=height[left], index=left;
	for(int i=left;i<=right;i++){
		if(height[i]<min) {
			min = height[i];
			index = i;
		}
	}
	return maximum(min*(right-left+1),maximum(largestArea(height,left,index-1), largestArea(height,index+1,right)));
}

int largestRectangleArea(vector<int>& height) {
 	if(height.size()==0) return 0;
 	else if(height.size()==1) return height[0];
 	else return largestArea(height, 0, height.size()-1);
}

int main(){
	int arr[] = {7,4};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	cout << largestRectangleArea(nums) << endl;
	return 0;
}