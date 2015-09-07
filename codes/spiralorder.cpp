#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ans;
        if(matrix.size()==0) return ans;
        bool right = true, left = false, up = false, down = false;
        int n = matrix.size(), m = matrix[0].size();
        int i=0, j=0, i_min=-1,i_max=n,j_min=-1,j_max=m,k=0;
        n = n*m;
        while(k<n){
        	if(right){
        		ans.push_back(matrix[i][j]);
        		j++;
        		if(j>=j_max){
        			right = false;
        			down = true;
        			i_min++; j--; i++;
        		}
        	} else if(down){
        		ans.push_back(matrix[i][j]);
        		i++;
        		if(i>=i_max){
        			down = false;
        			left = true;
        			j_max--; i--; j--;
        		}
        	} else if(left){
        		ans.push_back(matrix[i][j]);
        		j--;
        		if(j<=j_min){
        			left = false;
        			up = true;
        			i_max--; j++; i--;
        		}
        	} else if(up){
        		ans.push_back(matrix[i][j]);
        		i--;
        		if(i<=i_min){
        			up = false;
        			right = true;
        			j_min++; i++; j++;
        		}
        	}	
        	k++;
        }
        return ans;
}

int main(){
	int arr[] = {1,2};
	vector<int> temp;
	vector<vector<int> > matrix;
	int n=2, k=0, m=1;
	for(int i=0;i<m;i++){
		temp.clear();
		for(int j=0;j<n;j++){
			temp.push_back(arr[k]);
			k++;
		}
		matrix.push_back(temp);
	}
	// for(int i=0;i<matrix.size();i++){
	// 	for(int j=0;j<matrix[i].size();j++){
	// 		cout << matrix[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	vector<int> ans =  spiralOrder(matrix);
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}