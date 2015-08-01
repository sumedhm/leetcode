#include <iostream>
#include <string>

using namespace std;

bool Match(string s, string p, int ps, int pp){
		cout << s[ps] << ps << ", " << p[pp] << pp << endl;
		if(ps>=s.length()){
			if(pp>=p.length()){
				return true;
			} else if(p[pp+1]=='*'){
				return Match(s,p,ps,pp+1);
			} else return false;
		}
		if(pp>=p.length()) return false;
		if(p[pp+1]=='*'){
			if(s[ps]==p[pp] || p[pp]=='.'){		
				cout << s[ps] << ps << endl;		
				return (Match(s,p,ps+1,pp) || Match(s,p,ps,pp+2));
			} else {
				return Match(s, p, ps, pp+2);
			}
		}
		if(s[ps]==p[pp] || p[pp]=='.'){
			return Match(s, p, ps+1, pp+1);
		}
		return false;
}

bool isMatch(string s, string p){
	return Match(s, p, 0, 0);
}

int main(){
	//print(s.substr(1,3));
	cout << isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c") << endl;
	return 0;
}