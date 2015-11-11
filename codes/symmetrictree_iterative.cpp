#include <iostream>
#include <queue>


using namespace std;

bool palindrome(vector<int> t){
	int i=0,j=t.size()-1;
	for(int i=0;i<=j;i++) cout << t[i] << " ";
		cout << endl;
	while(i<j){
		if(t[i++]!=t[j--]) return false;
	}
	return true;
}

bool isSymmetric(TreeNode* root) {
	int null = -999;
	if(root==NULL) return true;
	queue<TreeNode *> q1;
	queue<TreeNode *> q2;
	TreeNode *tmp;
	vector<int> l;
	q1.push(root);
	while(!(q1.empty() && q2.empty())){
		if(!q1.empty()){
			l.clear();
			while(!q1.empty()){
				tmp = q1.front();
				q1.pop();
				l.push_back((tmp==NULL)?null:tmp->val);
				if(tmp!=NULL){
					q2.push(tmp->left);
					q2.push(tmp->right);
				}
			}
			if(!palindrome(l)) return false;
		} else {
			l.clear();
			while(!q2.empty()){
				tmp = q2.front();
				q2.pop();
				l.push_back((tmp==NULL)?null:tmp->val);
				if(tmp!=NULL){
					q1.push(tmp->left);
					q1.push(tmp->right);
				}
			}
			if(!palindrome(l)) return false;
		}
	}
	return true;
}

int main(){

	return 0;
}