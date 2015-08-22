#include <iostream>
#include <vector>

using namespace std;


bool isValidSudoku(vector<vector<char> >& board) {
        for(int i=0;i<9;i++){
        	vector<int> count(9,0);
        	for(int j=0;j<9;j++){
        		if(board[i][j]=='.') continue;
        		if(count[(board[i][j]-'0')-1]!=0) return false;
        		else count[(board[i][j]-'0')-1] = 1;
        	}
        }
        for(int i=0;i<9;i++){
        	vector<int> count(9,0);
        	for(int j=0;j<9;j++){
        		if(board[j][i]=='.') continue;
        		if(count[(board[j][i]-'0')-1]!=0) return false;
        		else count[(board[j][i]-'0')-1] = 1;
        	}
        }
        for(int i=0;i<3;i++)
        	for(int j=0;j<3;j++){
        		vector<int> count(9,0);
        		for(int k=0;k<3;k++)
        			for(int l=0;l<3;l++){
        				int x = k + 3*i;
        				int y = l + 3*j;
        				if(board[x][y]=='.') continue;
        				if(count[(board[x][y]-'0')-1]!=0) return false;
		        		else count[(board[x][y]-'0')-1] = 1;
        			}    
        	}

        return true;
}

bool solveSudoku(vector<vector<char> >& board) {
        for(int i=0;i<9;i++){
        	for(int j=0;j<9;j++){
        		if(board[i][j]!='.') continue;
        		for(char k='1';k<='9';k++){
        			board[i][j] = k;
        			if(isValidSudoku(board) && solveSudoku(board)) return true;
        			board[i][j] = '.';
        		}
        		return false;
        	}
        }
        return true;
}

int main(){
	int arr[] = {5,3,0,0,7,0,0,0,0,6,0,0,1,9,5,0,0,0,0,9,8,0,0,0,0,6,0,8,0,0,0,6,0,0,0,3,4,0,0,8,0,3,0,0,1,7,0,0,0,2,0,0,0,6,0,6,0,0,0,0,2,8,0,0,0,0,4,1,9,0,0,5,0,0,0,0,8,0,0,7,9};
	int k=0;
	vector<vector<char> > board;
	for(int i=0;i<9;i++){
		vector<char> temp;
    	for(int j=0;j<9;j++){
    		if(arr[k]==0) temp.push_back('.');
    		else temp.push_back(arr[k]+'0');
    		k++;
    	}
    	board.push_back(temp);
    }
    solveSudoku(board);
    for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
    		cout << board[i][j] << " ";
    	}
    	cout << endl;
    }
	return 0;
}