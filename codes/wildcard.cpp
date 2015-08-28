#include <iostream>
#include <string>

using namespace std;

bool Match(string s, string p, int sp, int pp){
	if(s==p) return true;
	else if(p=="") return false;
	int star = -1, ss = -1;
	while(sp<s.length()){
		if(s[sp]==p[pp] || p[pp]=='?'){
			sp++; pp++;
		} else if(p[pp]=='*'){
			star = pp; ss = sp; pp++;
		} else if(star!=-1){
			ss = sp = ss+1;
			pp = star+1;
		} else return false;
	}
	while(pp<p.length() && p[pp]=='*') pp++;
	if(pp==p.length()) return true;
	else return false;
}

bool isMatch(string s, string p) {
        return Match(s, p, 0, 0);
}

int main(){
	cout << isMatch("hi", "*?") << endl;
	return 0;
}