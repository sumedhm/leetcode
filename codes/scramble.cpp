#include <iostream>
#include <string>

using namespace std;

bool isScramble(string s1, string s2) {
	if(s1==s2) return true;
	if(s1.length()!=s2.length()) return false;
	int len = s1.length();
	bool scramble[len][len][len];
	for(int i=0;i<len;i++)
		for(int j=0;j<len;j++)
			for(int k=0;k<len;k++){
				if(k==0) scramble[i][j][k] = (s1[i]==s2[j]);
				else scramble[i][j][k] = false;
			}
	for(int k=1;k<len;k++){
		for(int i=0;i<len-k;i++){
			for(int j=0;j<len-k;j++){
				for(int p=0;p<k;p++){
					if((scramble[i][j][p] && scramble[i+p+1][j+p+1][k-p-1]) || (scramble[i][j+k-p][p] && scramble[i+p+1][j][k-p-1])){
						scramble[i][j][k] = true;
						break;
					}
				}
			}
		}
	}
	return scramble[0][0][len-1];
}

int main(){
	cout << isScramble("abc","cab") << endl;
	return 0;
}