#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void createTrees(int i, int j, vector<TreeNode *>& res){
	if(i>j) res.push_back(NULL);
	else {
		for(int k=i;k<=j;k++){

			vector<TreeNode *> left;
			createTrees(i,k-1,left);
			vector<TreeNode *> right;
			createTrees(k+1,j,right);
			
			for(int m=0;m<left.size();m++){
				for(int n=0;n<right.size();n++){
					TreeNode *tmp = new TreeNode(k);
					tmp->left = left[m];
					tmp->right = right[n];
					res.push_back(tmp);
				}
			}
		}
	}
	return;
}

vector<TreeNode*> generateTrees(int n) {
	vector<int> vals;
	vector<TreeNode*> res;
	createTrees(1,n,res);
	return res;
}

int main(){
	int n;
	cin >> n;
	return 0;
}