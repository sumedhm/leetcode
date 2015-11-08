#include <iostream>
#include <vector>
#include <string>

using namespace std;

int possible(int a, int b){
	if(b==-1 && a>=1 && a<=9) return 1;
	else if(a==0) return 0;
	a = a*10+b;
	if(a>=1 && a<=26) return 1;
	return 0; 
}

int numDecodings(string s) {
    if(s.length()==0) return 0;
    int num[s.length()+1];
    num[0] = 1;
    num[1] = possible(s[0]-'0',-1);
    for(int i=2;i<=s.length();i++){
    	num[i] = num[i-1] * possible(s[i-1]-'0',-1) + num[i-2] * possible(s[i-2]-'0',s[i-1]-'0');
    }
    return num[s.length()];
}

int main(){
	string s;
	cin >> s;
	cout << numDecodings(s) << endl;
	return 0;
}