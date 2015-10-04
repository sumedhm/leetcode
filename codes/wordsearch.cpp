#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool find(vector<vector<char> >& board, string str, int i, int j, string word){
	if(i<0 || i>=board.size() || j<0 || j>=board[i].size()) return false;
	int len = str.length();
	if(len==word.length()){
		return (str==word);
	} else if(word[len]==board[i][j]){
		board[i][j] = '.';
		if(find(board, str+word[len], i-1, j, word)) return true;
		else if (find(board, str+word[len], i+1, j, word)) return true;
		else if (find(board, str+word[len], i, j-1, word)) return true;
		else if (find(board, str+word[len], i, j+1, word)) return true;
		board[i][j] = word[len];
	}
	return false;
}

bool exist(vector<vector<char> > board, string word) {
	string str;
	vector<vector<char> > board1;
	board1 = board;
	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();j++){
			str = "";
			board = board1;
			if(board[i][j]==word[0]){
				board[i][j] = '.';
				str += word[0];
				if(str==word) return true;
				if(find(board, str, i-1, j, word)) return true;
				else if(find(board, str, i+1, j, word)) return true;
				else if(find(board, str, i, j-1, word)) return true;
				else if(find(board, str, i, j+1, word)) return true;
			}
		}
	}
    return false;
}

int main(){
	// char arr[] = {'a','b','c','e','s','f','c','s','a','d','e','e'};
	// char arr[] = {'c','a','a','a','a','a','b','c','d'};
	char arr[] = {'a','b','c','e','s','f','e','s','a','d','e','e'};
	vector<vector<char> > board;
	int k=0;
	vector<char> tmp;
	for(int i=0;i<3;i++){
		tmp.clear();
		for(int j=0;j<4;j++){
			tmp.push_back(arr[k]);
			k++;
		}
		board.push_back(tmp);
	}
	string word;
	while(true){		
		cin >> word;
		cout << exist(board,word) << endl;
	}
	return 0;
}