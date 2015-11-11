#include <iostream>

using namespace std;

bool isSymmetric_(TreeNode *left, TreeNode *right){
	if(left==NULL || right==NULL) return (left===NULL && right==NULL);
	else return ((left->val == right->val) && (isSymmetric_(left->left, right->right)) && (isSymmetric_(left->right, right->left)));
}

bool isSymmetric(TreeNode* root) {
	if(root==NULL) return true;
	return isSymmetric_(root->left, root->right);
}

int main(){
	return 0;
}