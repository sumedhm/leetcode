#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int> >& matrix){
	int m = matrix.size(), n = matrix[0].size();
	if(m==0 || n==0) return;
	bool row = (matrix[0][0]==0);
	bool column = row;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(matrix[i][j]==0){
				if(i==0) row = true;
				if(j==0) column = true;
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}
	for(int i=m-1;i>0;i--){
		if(matrix[i][0]==0){
			for(int j=1;j<n;j++){
				matrix[i][j] = 0;
			}
		}
	}
	for(int j=n-1;j>0;j--){
		if(matrix[0][j]==0){
			for(int i=1;i<m;i++){
				matrix[i][j] = 0;
			}
		}
	}
	if(matrix[0][0]==0){
		if(column) for(int i=1;i<m;i++){
			matrix[i][0] = 0;
		}
		if(row) for(int i=1;i<n;i++){
			matrix[0][i] = 0;
		}
	}
	return;
}

int main(){
	int arr[] = {0,4,5,9,1,1,1,2,1};
	int k=0,m=3,n=3;
	vector<vector<int> > matrix;
	for(int i=0;i<m;i++){
		vector<int> temp;
		for(int j=0;j<n;j++){
			temp.push_back(arr[k]);
			k++;
		}
		matrix.push_back(temp);
	}
	setZeroes(matrix);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}