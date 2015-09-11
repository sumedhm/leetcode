#include <iostream>
#include <string>

using namespace std;


bool isNumber(string s) {
	bool num_start= false, decimal = false, exp = false, space = false, follow = true, digits = false;
	for(int i=0;i<s.length();i++){
		if(!num_start){
			
			if(s[i]==' ') continue;
			if(s[i]=='-' || s[i]=='+'){
				num_start = true;
			}
			else if(s[i]>='0'&&s[i]<='9'){
				num_start = true;
				digits = true;
			}
			else if(s[i]=='.'){
				follow = false;
				decimal = true;
				num_start = true;
			}
			else return false;
		} else {
			if(s[i]=='-' || s[i]=='+')  if(!exp || follow) return false;
			else continue;
			if(s[i]=='.'){
				if(decimal || space) return false;
				decimal = true;
				follow = true;
			} else if(s[i]=='e' || s[i]=='E'){
			    if(exp || space || !digits) return false;
				exp = true;
				follow = false;
				decimal = true;
			} else if((s[i]>='0' && s[i]<='9')){
				if(space) return false;
				digits = true;
				follow = true;
			} else if(s[i]==' '){
				space = true;
			}
			else return false;
		}
	}
	if(!digits) return false;
	if(!follow) return false;
	if(!num_start) return false;
	return true;  
}

int main(){
	cout << isNumber("e") << endl;
	return 0;
}