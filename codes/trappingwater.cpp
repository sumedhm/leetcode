#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b){
	return (a<b) ? a : b;
}

int max(int a, int b){
	return (a>b) ? a : b;
}

int trap(vector<int>& height){
	int water = 0;
	int n = height.size();
	int bar;
	int l[n-1], r[n-1];
	l[0] = 0;
	r[n-1] = 0;
	for(int i=1;i<n;i++){
		l[i] = max(l[i-1], height[i-1]);
	}
	for(int i=n-2;i>=0;i--){
		r[i] = max(r[i+1], height[i+1]);
	}
	for(int i=0;i<n;i++){
		bar = min(l[i], r[i]) - height[i];
		if(bar > 0) water+=bar;
	}
	return water;
}

int main(){

	int arr[] = {5,2,1,2,1,5};
	//int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> height(arr,arr+sizeof(arr)/sizeof(int));
	cout << trap(height) << endl;
	return 0;
}