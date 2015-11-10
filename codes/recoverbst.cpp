#include <iostream>

using namespace std;

void find(TreeNode *root, TreeNode *pre, TreeNode* first, TreeNode *second){
	if(root==NULL) return;
	find(root->left, pre, first, second);
	if(pre==NULL) pre = root;
	else {
		if(pre->val > root->val){
			if(first==NULL) first = pre;
			second = root;
		}
	}
	find(root->right, pre, first, second);
	return;
}

void recoverTree(TreeNode* root) {
	if(root==NULL) return;
	TreeNode *pre = NULL;
	TreeNode *first = NULL;
	TreeNode *second = NULL;
	int tmp;
	find(root, pre, first, second);
	tmp = first->val;
	first->val = second->val;
	second->val = tmp;
	return;
}

int main({
	return 0;
}