#include <iostream>
#include <vector>

using namespace std;

int minimum(int a, int b){
	return ((a<b) ? a : b);
}

int minPathSum(vector<vector<int> >& grid) {
	int m = grid.size();
	if(m==0) return 0;
	int n = grid[0].size();
	int pathsum[m+1][n+1];
	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++){
			if(i==0 || j==0){
				pathsum[i][j] = 0;
				continue;
			}
			if(i==1 || j==1){
				if(i==1){
					pathsum[i][j] = pathsum[i][j-1] + grid[i-1][j-1];
					continue;
				} else {
					pathsum[i][j] = pathsum[i-1][j] + grid[i-1][j-1];
				}
			} else {
				pathsum[i][j] = grid[i-1][j-1] + minimum(pathsum[i-1][j], pathsum[i][j-1]);
			}
		}
	}
	return pathsum[m][n];
}

int main(){
	int arr[] = {2,3,1,1,2,3};
    vector<int> temp;
    vector<vector<int> > matrix;
    int n=3, m=2, k=0;
    for(int i=0;i<n;i++){
            temp.clear();
            for(int j=0;j<m;j++){
                    temp.push_back(arr[k]);
                    k++;
            }
            matrix.push_back(temp);
    }
    cout << minPathSum(matrix) << endl;
	return 0;
}