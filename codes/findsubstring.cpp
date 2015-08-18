#include <iostream>
#include <string>
#include <vector>

using namespace std;

void permute(vector<string>& permutations, string maps, int l, int r){
	if(maps=="") return;
	else if(l==r) permutations.push_back(maps);
	else {
		char temp;
		for(int i=l;i<=r;i++){
			temp = maps[l];
			maps[l] = maps[i];
			maps[i] = temp;
			permute(permutations, maps, l+1, r);
			temp = maps[l];
			maps[l] = maps[i];
			maps[i] = temp;
		}
	}
}

bool match(string s, string m, int pos){
        int i;
        for(i=0;i<m.length();i++){
                if(s[pos+i]!=m[i]){
                        break;
                }
        }
        if(i==m.length()) return true;
        return false;
}

vector<int> findSubstring(string s, vector<string>& words) {
        vector<string> permutations;
        vector<int> ans;
        string maps = "";
        for(int i=0;i<words.size();i++){
        	maps += i+'0';
        }
        permute(permutations, maps, 0, maps.length()-1);
        for(int i=0;i<permutations.size();i++){
        	string mapping = "";
        	for(int j=0;j<permutations[i].length();j++){
        		mapping += words[permutations[i][j] - '0'];
        	}
        	permutations[i] = mapping;
        }
        for(int i=0;i<permutations.size();i++){
        	for(int j=0;j<s.length();j++){
        		if(match(s, permutations[i], j)){
        			ans.push_back(j);
        		}
        	}
        }
        return ans;
}

int main(){
	string arr[] = {"foo", "bar"};
	vector<string> words(arr, arr+sizeof(arr)/sizeof(string));
	vector<int> ans = findSubstring("foobarfoobarmanfoomanbarmanfoobar", words);
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << endl;
        }
	return 0;
}