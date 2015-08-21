#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int longestValidParentheses(string s) {
	if(s.length()<=1) return 0;
        stack<int> st;
        int max=0, cur=0, valid=-1;
        for(int i=0;i<s.length();i++){
        	if(s[i]=='('){
        		st.push(i);
        	} else if(s[i]==')'){
        		if(st.empty()){
	        		valid = i;
        		} else {
        			st.pop();
        			if(st.empty()){
        				cur = i - valid;
        				if(max < cur) max = cur;
        			} else {
        				cur = i - st.top();
        				if(max <cur) max = cur;
        			}
        		}
        	}
        }
        return max;
}

int main(){
	cout << longestValidParentheses("(()") << endl;
	return 0;
}
