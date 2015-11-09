#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool valid(string str){
	if(str=="0") return true;
	if(str[0]=='0') return false;
	int num=0;
	for(int i=0;i<str.length();i++){
		num = num*10 + (str[i]-'0');
	}
	return (num>=0 && num<=255);
}

void getA(string s, int len, string ip, vector<string>& res){
	int n = ip.length();
	if(len<1 || len>3) return;
	ip = "." + ip;
	string tmp;
	tmp = s.substr(0,len);
	if(valid(tmp)) res.push_back(tmp+ip);
	return;
}

void getAB(string s, int len, string ip, vector<string>& res){
	int n = ip.length();
	if(len<2) return;
	ip = "." + ip;
	string tmp;
	tmp = s.substr(len-1,1);
	if(valid(tmp)) getA(s,len-1,tmp+ip,res);
	tmp = s.substr(len-2,2);
	if(valid(tmp)) getA(s,len-2,tmp+ip,res);
	if(len<3) return;
	tmp = s.substr(len-3,3);
	if(valid(tmp)) getA(s,len-3,tmp+ip,res);
	return;
}

void getABC(string s, int len, string ip, vector<string>& res){
	int n = ip.length();
	if(len<3) return;
	ip = "." + ip;
	string tmp;
	tmp = s.substr(len-1,1);
	if(valid(tmp)) getAB(s,len-1,tmp+ip,res);
	tmp = s.substr(len-2,2);
	if(valid(tmp)) getAB(s,len-2,tmp+ip,res);
	tmp = s.substr(len-3,3);
	if(valid(tmp)) getAB(s,len-3,tmp+ip,res);
	return;
}

vector<string> restoreIpAddresses(string s) {
	//return as A.B.C.D
	int len = s.length();
	vector<string> res;
	if(len<4) return res;
	string ip;
	ip = s.substr(len-1,1);
	if(valid(ip)) getABC(s,len-1,ip,res);
	ip = s.substr(len-2,2);
	if(valid(ip)) getABC(s,len-2,ip,res);
	ip = s.substr(len-3,3);
	if(valid(ip)) getABC(s,len-3,ip,res);
	return res;
}

int main(){
	string str;
	cin >> str;
	vector<string> ans = restoreIpAddresses(str);
	for(int i=0;i<ans.size();i++) cout << ans[i] << endl;
	return 0;
}