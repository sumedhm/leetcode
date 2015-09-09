#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid){
        int m = obstacleGrid.size();
        if(m==0) return 0;
        int n = obstacleGrid[0].size();
	    if(n==0) return 0;
        if(obstacleGrid[0][0]==1) return 0;
        if(m==1){
            for(int i=0;i<n;i++){
                if(obstacleGrid[0][i]==1) return 0;
            }
            return 1;
        }
        if(n==1){
            for(int i=0;i<m;i++) if(obstacleGrid[i][0]==1) return 0;
            return 1;
        }
        int paths[m+1][n+1];
        for(int i=0;i<m+1;i++){
        	for(int j=0;j<n+1;j++){
                if(i>0 && j>0 && obstacleGrid[i-1][j-1]==1){
                        paths[i][j] = 0;
                        continue;
                }
        		if(i==0 || j==0){
        			paths[i][j] = 0;
        		} else if(i==1 || j==1){
                    if(i==1 && j==1) paths[i][j] = 1;
                    else if(i==1) paths[i][j] = paths[i][j-1];
                    else paths[i][j] = paths[i-1][j];
        		} else {
        			paths[i][j] = paths[i-1][j] + paths[i][j-1];
        		}
        	}
        }
        return paths[m][n];
}

int main(){
    int arr[] = {0,0,1,1,0,0};
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
    cout << uniquePathsWithObstacles(matrix) << endl;
	return 0;
}