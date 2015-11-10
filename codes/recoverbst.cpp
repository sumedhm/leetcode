#include <iostream>

using namespace std;

TreeNode *pre, *first, *second;
void find(TreeNode *root){
	if(root==NULL) return;
	find(root->left);
	if(pre==NULL) pre = root;
	else {
		if(pre->val > root->val){
			if(first==NULL) first = pre;
			second = root;
		}
		pre = root;
	}
	find(root->right);
	return;
}

void recoverTree(TreeNode* root) {
	if(root==NULL) return;
	pre = NULL;
	first = NULL;
	second = NULL;
	int tmp;
	find(root);
	tmp = first->val;
	first->val = second->val;
	second->val = tmp;
	return;
}

int main({
	return 0;
}