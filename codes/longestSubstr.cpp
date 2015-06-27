#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string str){
	int pointer, current;
	int max_len = 0, cur_len = 0;
	vector<char> visited;
	pointer = current = 0;
	for(int i=0;i<str.length();i++){
		int j;
		for(j=current;j<i;j++){
			if(str[i]==str[j]){
				if(cur_len > max_len){
					max_len = cur_len;
					pointer = current;
				}
				current = j+1;
				cur_len = i-j;
				break;
			} else continue;
		}
		if(j==i){
			cur_len++;
		}
		if(cur_len > max_len){
			max_len = cur_len;
			pointer = current;
		}
	}
	//cout << pointer << endl;
	return max_len;
}

int main(){

	string input;
	cin >> input;

	cout << lengthOfLongestSubstring(input) << endl;
	return 0;
}