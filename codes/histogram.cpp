#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& height){
	stack<int> st;
	if(height.size()==0) return 0;
	int maxArea = 0, area, tmp, i=0;
	while(i<height.size()){
		if(st.empty() || height[i]>=height[st.top()]) st.push(i++);
		else {
			tmp = st.top();
			st.pop();
			area = height[tmp] * (st.empty() ? i : i-st.top()-1);
			if(area>maxArea) maxArea = area;
		}
	}
	while(!st.empty()){
		tmp = st.top();
		st.pop();
		area = height[tmp] * (st.empty() ? i : i-st.top()-1);
		if(area>maxArea) maxArea = area;
	}
	return maxArea;
}

int main(){
	int arr[] = {5,1,1,1,1,1};
	vector<int> height(arr, arr+sizeof(arr)/sizeof(int));
	cout << largestRectangleArea(height) << endl;
	return 0;
}