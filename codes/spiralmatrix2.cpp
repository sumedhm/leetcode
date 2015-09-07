#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generateMatrix(int n) {
        bool right = true, left = false, up = false, down = false;
        int i = 0, j = 0, k = 1, i_min = -1, i_max = n, j_min = -1, j_max = n;
        vector<vector<int> > matrix;
        for(int x=0;x<n;x++){
        	vector<int> temp;
        	for(int y=0;y<n;y++){
        		temp.push_back(0);
        	}
        	matrix.push_back(temp);
        }
        n *= n;
        while(k<=n){
        	if(right){
        		matrix[i][j] = k;
        		j++;
        		if(j==j_max){
        			right = false;
        			down = true;
        			j--; i++;
        			i_min++;
        		}
        	} else if(down){
        		matrix[i][j] = k;
        		i++;
        		if(i==i_max){
        			down = false;
        			left = true;
        			i--; j--;
        			j_max--;
        		}
        	} else if(left){
        		matrix[i][j] = k;
        		j--;
        		if(j==j_min){
        			left = false;
        			up = true;
        			i--; j++;
        			i_max--;
        		}
        	} else if(up){
        		matrix[i][j] = k;
        		i--;
        		if(i==i_min){
        			up = false;
        			right = true;
        			i++; j++;
        			j_min++;
        		}
        	}
        	k++;
        }
        return matrix;
}

int main(){
	int n = 5;
	vector<vector<int> > matrix = generateMatrix(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}