#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
		if(s.length()==0) return 0;
		int cur = 0, last=0;
		for(int i=0;i<s.length();i++){
			if(s[i]==' '){
				if(cur!=0){
					last = cur;
					cur = 0;
				}
			}
			else cur++;
		}
		if(cur!=0) last = cur;
		return last;
}

int main(){
	cout << lengthOfLastWord("Hello ") << endl;
	return 0;
}