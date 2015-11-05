#include <iostream>
#include <vector>

using namespace std;

int maximalRectangle(vector<vector<char> >& matrix) {
	if(matrix.size()==0) return 0;
	int n = matrix.size();
	int m = matrix[0].size();
	int ones[n][m];
	int area = 0, tmp;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(j==0) ones[i][j] = (matrix[i][j]-'0');
			else ones[i][j] = (matrix[i][j]=='0') ? 0 : (ones[i][j-1]+1);
		}
	}
	int min;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			min = ones[j][i];
			for(int k=j;k>=0;k--){
				if(ones[k][i]==0) break;
				if(ones[k][i]<min) min = ones[k][i];
				tmp = (j-k+1)*min;
				if(tmp>area) area = tmp;
			}
		}
	}
	return area;
}

int main(){
	int n,m;
	cin >> n >>m;
	vector<vector<char> > matrix;
	vector<char> temp;
	char tmp;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> tmp;
			temp.push_back(tmp);
		}
		matrix.push_back(temp);
	}
	cout << maximalRectangle(matrix) << endl;
 	return 0;
}