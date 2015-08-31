#include <iostream>
#include <vector>

using namespace std;

void reverse_row(vector<vector<int> >& matrix, int i){
	int j=0,k=matrix[i].size()-1;
	int tmp;
	while(j<k){
		tmp = matrix[i][j];
		matrix[i][j] = matrix[i][k];
		matrix[i][k] = tmp;
		j++; k--;
	}
	return;
}

void transpose(vector<vector<int> >& matrix){
	int n = matrix[0].size();
	int tmp;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			tmp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = tmp;
		}
	}
	return;
}

void rotate(vector<vector<int> >& matrix) {
		int n = matrix[0].size();
		transpose(matrix);
		for(int i=0;i<n;i++) reverse_row(matrix, i);
        return;
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	vector<int> temp;
	vector<vector<int> > matrix;
	int n=4, k=0;
	for(int i=0;i<n;i++){
		temp.clear();
		for(int j=0;j<n;j++){
			temp.push_back(arr[k]);
			k++;
		}
		matrix.push_back(temp);
	}
	rotate(matrix);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}