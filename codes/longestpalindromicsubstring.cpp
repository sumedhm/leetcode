#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
    int len=1, cur_len, start=0, end;
    int str_len = s.length();
    for(int i=0;i<str_len;i++){
        int j=i-1,k=i+1;
        cur_len = 1;
        //Check odd length palindrome around i.
        while(j>=0 && k<=str_len-1){
        	if(s[j]==s[k]){
        		cur_len += 2;
        		if(cur_len>len){
        			len = cur_len;
        			start = j;
        			end = k;
        		}
        		j--; k++;        		
        	} else break;
        }        
        
        //Check even length palindrome around i.
        j=i; k=i+1;
        cur_len=0;
        while(j>=0 && k<=str_len-1){
        	if(s[j]==s[k]){
        		cur_len+=2;
        		if(cur_len>len){
        			len = cur_len;
        			start = j;
        			end = k;
        		}
        		j--;k++;        		
        	} else break;
        }
    }

    return s.substr(start, len);
}

int main(){

	cout << longestPalindrome("a") << endl;

	return 0;
}
