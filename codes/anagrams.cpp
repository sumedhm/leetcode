#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

void quickSort(char *str, int left, int right){
	int i = left, j = right;
	char tmp;
	char pivot = *(str+(left+right)/2);
	while(i<=j){
		while(*(str+i)<pivot) i++;
		while(*(str+j)>pivot) j--;
		if(i<=j){
			tmp = *(str+i);
			*(str+i) = *(str+j);
			*(str+j) = tmp;
			i++;j--;
		}
	}
	if(j>left) quickSort(str, left, j);
	if(i<right) quickSort(str, i, right);
	return;
}

bool less_than(string str1, string str2){
	if(str1==str2) return true;
	int i=0, j=0;
	while(i<str1.length() && j<str2.length()){
		if(str1[i]<str2[j]) return true;
                else if(str1[i]>str2[j]) return false;
		i++; j++;
	}
	if(j<str2.length()) return true;
	return false;
}

vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;
        vector<string> key;
        bool found = false;
        for(int i=0;i<strs.size();i++){
                char* tmp = (char *) malloc (sizeof(strs[i].c_str()));
                strcpy(tmp, strs[i].c_str());
        	quickSort(tmp, 0, strs[i].length()-1);
        	string sorted(tmp);
        	found = false;
        	int j;
        	for(j=0;j<ans.size();j++){
        		if(key[j]==sorted){
        			found = true;
        			break;
        		}
        	}
        	if(found){
        		bool inserted = false;
                        int size = ans[j].size();
        		for(int k=0;k<size;k++){
                               if(less_than(strs[i], ans[j][k])){
                                        inserted = true;
                                        ans[j].insert(ans[j].begin()+k, strs[i]);
                                        break;
                                }
                        }
                        if(!inserted){
                                ans[j].push_back(strs[i]);
                        }
                } else {
                        key.push_back(sorted);
                        vector<string> temp;
                        temp.push_back(strs[i]);
        		ans.push_back(temp);
        	}
        }
        return ans;
}

int main(){
	string arr[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<string> strs(arr,arr+sizeof(arr)/sizeof(string));
        cout << less_than("tea","eat") << endl;
	vector<vector<string> > ans = groupAnagrams(strs);
        for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}