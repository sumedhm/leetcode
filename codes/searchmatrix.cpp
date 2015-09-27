#include <iostream>
#include <vector>

using namespace std;

int binarySearchRow(vector<vector<int> > matrix, int top, int bottom, int target){
    // cout << top << "," << bottom << endl;
    if(top>bottom) return -1;
    int n = matrix[0].size();
    if(matrix[top][0]>target){
        return -1;
    } else if(matrix[bottom][n-1]<target){
        return -1;
    }
    if(matrix[top][0]<=target && matrix[top][n-1]>=target) return top;
    else if(matrix[bottom][0]<=target && matrix[bottom][n-1]>=target) return bottom;
    int mid = (top+bottom)/2;
    if(matrix[mid][0]<=target && matrix[mid][n-1]>=target) return mid;
    else{
        if(matrix[mid][0]<target){
            return binarySearchRow(matrix, mid+1, bottom-1, target);
        } else {
            return binarySearchRow(matrix, top+1, mid-1, target);
        }
    }
}

bool binarySearchVal(vector<vector<int> > matrix, int row, int left, int right, int target){
    if(left>right) return false;
    if(matrix[row][left]==target) return true;
    else if(matrix[row][right]==target) return true;
    if(matrix[row][left]>target || matrix[row][right]<target) return false;
    int mid = (left+right)/2;
    if(matrix[row][mid]==target) return true;
    if(matrix[row][mid]<target){
        return binarySearchVal(matrix, row, mid+1, right-1, target);
    } else {
        return binarySearchVal(matrix, row, left+1, mid-1, target);
    }
}

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int row = binarySearchRow(matrix, 0, matrix.size()-1, target);
    if(row==-1) return false;
    // cout << row << endl;
    return binarySearchVal(matrix, row, 0, matrix[0].size()-1, target);
}

int main(){
	int arr[] = {1,3,5,7,10,11,16,20,23,30,34,50};
	int k=0,m=3,n=4;
	vector<vector<int> > matrix;
	for(int i=0;i<m;i++){
		vector<int> temp;
		for(int j=0;j<n;j++){
			temp.push_back(arr[k]);
			k++;
		}
		matrix.push_back(temp);
	}
	cout << searchMatrix(matrix, 21) << endl;
	return 0;
}