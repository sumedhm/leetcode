#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int longestValidParentheses(string s) {
        stack<char> st;
        char c;
        int max=0, cur=0, valid = 0;
        for(int i=0;i<s.length();i++){
        	if(s[i]=='('){
        		st.push(s[i]);
        	} else if(s[i]==')'){
        		if(st.empty()){
        			//do nothing
        		} else {
        			c = st.top();
        			if(c=='('){
        				st.pop();
        				int x = 0;
        				while(!st.empty() && st.top()=='('){
        					x++;
        					st.pop();
        				}
        				st.push('#');
        				for(int i=0;i<x;i++) st.push('(');
        			} else if(c=='#'){
        				//
        			} else {        				
        				st.push('=');
        			}
        		}
        	}
        }
        cur = 0;
        while(!st.empty()){
        	c = st.top();
        	cout << c;
        	if(c=='#'){
        		cur++;
        	} else {
        		if(max < cur) max = cur;
        		cur = 0;
        	}
        	st.pop();        	
        }
        cout << endl;
        if(max<cur) max = cur;
        return 2*max;
}

int main(){
	cout << longestValidParentheses("()(())") << endl;
	return 0;
}
