#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int longestValidParentheses(string s) {
        stack<char> st;
        st.push('$');
        char c;
        int max=0, cur=0;
        for(int i=0;i<s.length();i++){
        	cur = 0;
        	if(s[i]=='('){
        		st.push(s[i]);
        	} else if(s[i]==')'){
        		if(st.empty()){
        			//do nothing
        		} else {
        			c = st.top();
        			if(c=='$' || c==')') continue;
        			if(c=='('){
        				st.pop();     
        				cur = 1;  
        				c = st.top();
        				while(c!='$' && c!='(' && c!=')'){
        					st.pop();
        					cur += c-'0';
        					c = st.top();
        				}
        				st.push(cur+'0');
        				if(max<cur) max = cur;
        			} else {
        				st.pop();
        				cur = c-'0';
        				c = st.top();
        				while(c!='$' && c!='(' && c!=')'){
        					st.pop();
        					cur += c-'0';
        					c = st.top();
        				}
        				if(c=='('){
        					cur++;
        					st.pop();
        				} else {
        					st.push(')');
        					if(max < cur) max = cur;
        					cur = 0;
        					continue;
        				}
        				c = st.top();
        				while(c!='$' && c!='(' && c!=')'){
        					st.pop();
        					cur += c-'0';
        					c = st.top();
        				}
        				st.push(cur+'0');
        				if(max<cur) max = cur;
        			}
        		}
        	}
        }
        // c = st.top();
        // while(c!='$'){
        // 	st.pop();
        // 	if(c=='(') break;
        // 	else{
        // 		cur += c-'0';
        // 	}
        // 	c = st.top();
        // }
        if(max<cur) max = cur;
        return 2*max;
}

int main(){
	cout << longestValidParentheses(")(())))(())())") << endl;
	return 0;
}
