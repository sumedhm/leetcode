#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs){
        if(strs.size()==0) return "";
	int i = 0;
        string prefix = strs[i];
        for(i=1;i<strs.size();i++){
        	int j=0;
        	while(j<prefix.length() && j<strs[i].length()){
        		if(prefix[j]==strs[i][j]) j++;
        		else break;
        	}
        	prefix.erase(prefix.begin()+j,prefix.end());
                //prefix[j] = '\0';
        }
        return prefix;
}

int main(){
	string arr[] = {"abcduhwr","abcdwu","abcdwioe","abc"};
	vector<string> strs(arr, arr+sizeof(arr)/sizeof(string));
	cout << longestCommonPrefix(strs) << endl;
	return 0;
}