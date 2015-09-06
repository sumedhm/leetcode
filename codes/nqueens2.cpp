#include <iostream>
#include <vector>
#include <string>

using namespace std;

void totalNQueens_(int *ans, vector<string>& temp, int column[], int diagonal[], int antiDiagonal[], int n, int k){
	if(k>n) return;
	if(k==n){
		*ans = *ans + 1;
		return;
	} else {
		string tmp = "";
		for(int i=0;i<n;i++) tmp += ".";
		for(int i=0;i<n;i++){
			if(column[i]==1 || diagonal[i+k]==1 || antiDiagonal[n-1-i+k]==1) continue;
			tmp[i] = 'Q';
			temp.push_back(tmp);
			column[i]=1;
			diagonal[i+k]=1;
			antiDiagonal[n-1-i+k]=1;
			totalNQueens_(ans, temp, column, diagonal, antiDiagonal, n, k+1);
			column[i]=0;
			diagonal[i+k]=0;
			antiDiagonal[n-1-i+k]=0;
			temp.pop_back();
			tmp[i] = '.';
		}
	}
	return;
}

int totalNQueens(int n) {
		int ans = 0;
        if(n<=1) return n;
        int column[n];
        int diagonal[2*n-1];
        int antiDiagonal[2*n-1];
        for(int i=0;i<n;i++) column[i] = 0;
    	for(int i=0;i<2*n-1;i++){
    		diagonal[i] = antiDiagonal[i] = 0;
    	}
        vector<string> temp;
        totalNQueens_(&ans, temp, column, diagonal, antiDiagonal, n, 0);
        return ans;
}

int main(){
	cout << totalNQueens(4) << endl;
	return 0;
}