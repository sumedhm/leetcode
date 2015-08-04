#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s){
	stack<char> parentheses;
	for(int i=0;i<s.length();i++){
		if(s[i]=='(' || s[i]=='{' || s[i]=='['){
			parentheses.push(s[i]);
		} else{
			if(parentheses.empty()) return false;
			char bracket = parentheses.top();
			if(s[i]==')' && bracket=='(') parentheses.pop();
			else if(s[i]=='}' && bracket=='{') parentheses.pop();
			else if(s[i]==']' && bracket=='[') parentheses.pop();
			else return false;
		}
	}
	if(parentheses.empty()) return true;
    return false;
}

int main(){
	cout << isValid("]") << endl;
	return 0;
}