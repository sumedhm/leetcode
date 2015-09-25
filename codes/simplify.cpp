#include <iostream>
#include <string>
#include <stack>

using namespace std;

string simplifyPath(string path) {
	stack<string> s;
	string tmp;
	for(int i=0;i<path.length();i++){
		if(path[i]=='/'){
			tmp = "";
		}else if(path[i]=='.'){
			string temp = "";
			while(i<path.length() && path[i]=='.'){
				temp += "."; i++;
			}
			if(temp=="."){
				continue;
			} else if(temp==".."){
				if(!s.empty()) s.pop();
				else{
					tmp = "..";
					s.push(temp);
				}
			} else{
				s.push(temp);
			}
		} else {
			if(s.empty() || tmp==""){
				tmp = "";
				s.push(tmp+path[i]);
				tmp = path[i];
				continue;
			}
			tmp = s.top();
			s.pop();
			s.push(tmp+path[i]);
		}
	}
	if(s.empty()) return "/";
	tmp = "";
	while(!s.empty()){
		tmp = "/" + s.top() + tmp;
		s.pop();
	}
	return tmp;
}

int main(){
	cout << simplifyPath("/.hidden") << endl;
	return 0;
}