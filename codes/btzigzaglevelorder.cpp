#include <iostream>

using namespace std;
   
void reverse(vector<int>& l){
    int i=0,j=l.size()-1;
    int tmp;
    while(i<j){
        tmp = l[i];
        l[i] = l[j];
        l[j] = tmp;
        i++; j--;
    }
    return;
}

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root==NULL) return res;
        vector<int> l;
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        q1.push(root);
        TreeNode *tmp;
        while(!(q1.empty() && q2.empty())){
            l.clear();
            if(!q1.empty()){
                while(!q1.empty()){
                    tmp = q1.front();
                    q1.pop();
                    l.push_back(tmp->val);
                    if(tmp->left!=NULL) q2.push(tmp->left);
                    if(tmp->right!=NULL) q2.push(tmp->right);
                }
                res.push_back(l);
            } else {
                while(!q2.empty()){
                    tmp = q2.front();
                    q2.pop();
                    l.push_back(tmp->val);
                                if(tmp->left!=NULL) q1.push(tmp->left);
                                if(tmp->right!=NULL) q1.push(tmp->right);
                }
                reverse(l);
                res.push_back(l);
            }
        }
        return res;
}

int main(){
	return 0;
}