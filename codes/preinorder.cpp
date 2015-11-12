#include <iostream>

using namespace std;

int find(vector<int>& inorder, int left, int right, int key){
	/*if(key==inorder[left]) return left;
	if(key==inorder[right]) return right;
	int mid = (left+right)/2;
	if(key==inorder[mid]) return mid;
	if(key>inorder[mid]) return find(inorder,mid+1,right,key);
	return find(inorder,left,mid-1,key);*/
	for(int i=left;i<=right;i++) if(key==inorder[i]) return i;
}

TreeNode* buildTree_(vector<int>& inorder, int l1, int r1, vector<int>& preorder, int l2, int r2) {
	if(l1>r1) return NULL;
	int r = preorder[l2];
	TreeNode *root = new TreeNode(r);
	if(l1==r1) return root;
	int d1 = find(inorder,l1,r1,r);
	int d2 = l2+(d1-l1);
	root->left = buildTree_(inorder,l1,d1-1,preorder,l2+1,d2);
	root->right = buildTree_(inorder,d1+1,r1,preorder,d2+1,r2);
	return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if(inorder.size()==0) return NULL;
	int n = inorder.size();
	return buildTree_(inorder,0,n-1,preorder,0,n-1);
}

int main(){
	return 0;
}