#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void inorder(TreeNode *root, vector<int>& res){
	if(root==NULL) return;
	if(root->left!=NULL) inorder(root->left, res);
	res.push_back(root->val);
	if(root->right!=NULL) inorder(root->right, res);
	return;
}

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> res;
	if(root==NULL) return res;
	inorder(root, res);
	return res;
}

int main(){
	return 0;
}