#include <iostream>
#include <stdlib.h>
#include <climits>
#include <vector>

using namespace std;

struct node{
	int val;
	int max;
	int min;
	bool leaf;
	node *left;
	node *right;
	node(int x, int a, int b, node *l, node *r) : val(x),min(a),max(b),left(l),right(r){}
};

int minimum(int a, int b, vector<int> arr){
	if(a==INT_MAX) return b;
	else if(b==INT_MAX) return a;
	return ((arr[a]<arr[b])?a:b);
}

long long int maximum(int a, int b){
	return ((a>b)?a:b);
}

node *construct_tree(vector<int> arr, int min, int max){
	node *root = new node(-1, min, max, NULL, NULL);
	if(min==max){
		root->leaf = true;
		root->val = min;
	} else {
		root->leaf = false;
		int mid = (min+max)/2;
		root->left = construct_tree(arr, min, mid);
		root->right = construct_tree(arr, mid+1, max);
		root->val = minimum(root->left->val, root->right->val, arr);
	}
	return root;
}

int getMinimum(node *root, int left, int right, vector<int> arr){
	if(left<=root->min && right>=root->max) return root->val;
	else if((left > root->max) || (right < root->min)) return INT_MAX;
	else return minimum(getMinimum(root->left, left, right, arr), getMinimum(root->right, left, right, arr), arr);
}

int maxArea(vector<int> heights, int left, int right, node *root){
	if(left>right) return 0;
	if(left==right) return heights[left];
	int min = getMinimum(root,left,right,heights);
	return maximum(heights[min]*(right-left+1), maximum(maxArea(heights,left,min-1,root),maxArea(heights,min+1,right,root)));
}

int largestRectangleArea(vector<int>& height){
	if(height.size()==0) return 0;
	if(height.size()==1) return height[0];
	node *root;
	root = construct_tree(height, 0, height.size()-1);
	return maxArea(height, 0, height.size()-1, root);
}

int main(){
	int size;
	int arr[] = {6, 2, 5, 4, 5, 1, 6};
	vector<int> heights(arr,arr+sizeof(arr)/sizeof(int));
	cout << largestRectangleArea(heights) << endl;
}