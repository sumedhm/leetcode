#include <iostream>
#include <climits>
#define ll long long int
using namespace std;



bool valid(TreeNode* root, int min, long long int max){
	if(root==NULL) return true;
	else if(root->val <= min || root->val >= max) return false;
	return (valid(root->left,min,root->val) && valid(root->right,root->val,max));
}

bool isValidBST(TreeNode* root) {
	if(root==NULL) return true;
	return valid(root,INT_MIN, INT_MAX+1);
}