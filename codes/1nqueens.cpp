#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(vector<string> board, int n){
	int size = board.size();
	if(size<=1) return true;
	vector<int> pos;
	for(int i=0;i<size;i++){
		for(int j=0;j<n;j++){
			if(board[i][j]=='Q'){
				pos.push_back(j);
				break;
			}
		}
	}
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
			int x = pos[i] - (j-i);
			int y = pos[i] + (j-i);
			if(x>=0 && pos[j]==x) return false;
			if(y<size && pos[j]==y) return false;
			if(pos[i]==pos[j]) return false;
		}
	}
	return true;
}

void solveNQueens_(vector<vector<string> >& ans, vector<string>& temp, int n, int k){
	if(k>n || !isValid(temp, n)) return;
	if(k==n){
		ans.push_back(temp);
		return;
	} else {
		string tmp = "";
		for(int i=0;i<n;i++) tmp += ".";
		for(int i=0;i<n;i++){
			tmp[i] = 'Q';
			temp.push_back(tmp);
			solveNQueens_(ans, temp, n, k+1);
			temp.pop_back();
			tmp[i] = '.';
		}
	}
	return;
}

vector<vector<string> > solveNQueens(int n){
        vector<vector<string> > ans;
		if(n==0) return ans;
        vector<string> temp;
        solveNQueens_(ans, temp, n, 0);
        return ans;
}

int main(){
	vector<vector<string> > ans = solveNQueens(9);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout << ans[i][j] << endl;
		}
		cout << endl;
	}
	return 0;
}