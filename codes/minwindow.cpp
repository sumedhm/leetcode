#include <iostream>
#include <string>
#include <map>

using namespace std;

string minWindow(string s, string t) {
	if(t=="") return "";
	if(s==t) return s;
	if(t.length()>s.length()) return "";
	int start=0,end = 0, begin;
	map<char, int> required;
	map<char, int> found;
	int chars = 0;
	for(int i=0;i<t.length();i++) required[t[i]]++;
	int i=0;
	/*while(chars<t.length()){
		if(required.find(s[i])==required.end()){
			//do nothing
		} else {			
			found[s[i]]++;
		}
		i++;
		if(i>=s.length()) return "";
	}
	int min = i-start;
	end = i-1;*/
	int min = s.length()+1;
	begin = start;
	while(i<s.length()){
		// cout << start << "," << i << "," << s[i] << endl;
		if(required.find(s[start])==required.end()){
			start++;
		} else if(required.find(s[i])==required.end()){
			//
		} else {
			if(i==start){
				if(chars==0){
					chars++;
					if(chars==t.length()){
						return t;
					}
					found[s[start]]++;
				}
			} else if(s[i]==s[start]){
				found[s[i]]++;
				while(true){
					if(required.find(s[start])==required.end()){
						start++;
						continue;
					}
		// cout << start << "," << i << "," << s[i] << found[s[i]] << "-" << required[s[i]] << endl;
					if(required[s[start]]>=found[s[start]]){
						// cout << i << chars<< endl;
						// cout << required[s[start]] << "-" << found[s[start]] << endl;
						if(i==start) break;
						else if(chars<t.length()) chars++;
						else if(min > i-start+1){
							min = i-start+1;
							begin = start;
							end = i;
						}
						if(chars==t.length()){
							if(min > i-start+1){
								min = i-start+1;
								end = i;
								begin = start;
							}
						}
						break;
					}
					if(required.find(s[start])==required.end()) continue;
					if(required[s[start]]==found[s[start]]){
						if(min > i-start+1){
							min = i-start+1;
							end = i;
							begin = start;
						}
						break;
					} else {
						found[s[start]]--;
					}
					start++;
				}
			} else {
				if(found[s[i]]<required[s[i]]) chars++;
				found[s[i]]++;
				if(chars==t.length()){
					if(min > i-start+1){
						min = i-start+1;
						end = i;
						begin = start;
					}
				} 
				// cout << chars << "," << start << "," << end << "," <<i << endl;
			}
		}
		i++;
	}
	/*for(map<char,int>::iterator it=required.begin();it!=required.end();++it){
		cout << it->first << ", " << it->second << endl;
	}
	for(map<char,int>::iterator it=found.begin();it!=found.end();++it){
		cout << it->first << ", " << it->second << endl;
	}*/
	if(min==s.length()+1) return "";
	string res = "";
	for(int i=begin;i<=end;i++){
		res += s[i];
	}
	return res;
}

int main(){
	string str1, str2;
	cin >> str1 >> str2;
	cout << minWindow(str1,str2) << endl;
	return 0;
}