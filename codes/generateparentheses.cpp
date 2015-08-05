#include <iostream>
#include <vector>

using namespace std;

void getCombinations(vector<string>& ans, string str, int open, int close){
	if(close < open) return;
	else if(close==0 && open==0){
		ans.push_back(str);
	} else {
		if(open!=0){
			getCombinations(ans, str+"(", open-1, close);
		}
		if(close!=0){
			getCombinations(ans, str+")", open, close-1);
		}
	}
	return;
}

vector<string> generateParenthesis(int n) {
        vector<string> ans;
        getCombinations(ans, "", n, n);
        return ans;
}

int main(){

	vector<string> ans = generateParenthesis(3);
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << endl;
	}
	return 0;
}