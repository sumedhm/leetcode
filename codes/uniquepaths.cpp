#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n) {
		if(m==0 || n==0) return 0;
        if(m==1 || n==1) return 1;
        int paths[m+1][n+1];
        for(int i=0;i<m+1;i++){
        	for(int j=0;j<n+1;j++){
        		if(i==0 || j==0){
        			paths[i][j] = 0;
        		} else if(i==1 || j==1){
        			paths[i][j] = 1;
        		} else {
        			paths[i][j] = paths[i-1][j] + paths[i][j-1];
        		}
        	}
        }
        return paths[m][n];
}

int main(){
	cout << uniquePaths(3,3) << endl;
	return 0;
}