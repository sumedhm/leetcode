#include <iostream>
#include <string>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
	int n = s1.length(), m = s2.length();
	if(n+m!=s3.length()) return false;
	bool in[n+1][m+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 && j==0){
				in[i][j] = true;
			} else if(i==0){
				in[i][j] = (in[i][j-1]) ? (s2[j-1]==s3[j-1]) : false;
			} else if(j==0){
				in[i][j] = (in[i-1][j]) ? (s1[i-1]==s3[i-1]) : false;
			} else {
				in[i][j] = (((in[i-1][j]) ? (s1[i-1]==s3[i+j-1]) : false)  || ((in[i][j-1]) ? (s2[j-1]==s3[i+j-1]) : false));
			}
		}
	}
	return in[n][m];
}

int main(){
	cout << isInterleave("aa","ab","aaba") << endl;
	return 0;
}