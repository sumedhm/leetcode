#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> letterCombinations(string digits){
        vector<string> ans;
        if(digits.length()==0) return ans;
        string mapping[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string combination = "";
        int len = digits.length();
        int cur[len];
        int i,j;
        for(i=0;i<len;i++){
        	cur[i] = 0;
        }
        
        combination = "";
        for(i=0;i<len;i++){
                combination += mapping[digits[i]-'0'][cur[i]];
        }
        ans.push_back(combination);
        i = j = digits.length()-1;
        while(j!=-1){
                cur[i]++;
                if(cur[i]<mapping[digits[i]-'0'].length()){
                        combination[i] = mapping[digits[i]-'0'][cur[i]];
                        ans.push_back(combination);
                        continue;
                }
                while(cur[i]>=mapping[digits[i]-'0'].length()){
                        i--;
                        if(i==-1) break;
                        cur[i]++;
                }
                j = i;
                if(j==-1) break;
                while(i<len-1){
                        combination[i] = mapping[digits[i]-'0'][cur[i]];
                        i++;
                        cur[i] = 0;
                }
                combination[i] = mapping[digits[i]-'0'][cur[i]];
                ans.push_back(combination);
        }
        return ans;
} 

int main(){

	vector<string> ans = letterCombinations("232");
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << endl;
	}
	return 0;
}