#include <iostream>
#include <string>
#include <vector>

using namespace std;

int binary_to_int(string str){
	int j=str.length()-1,p=1;
	int tmp;
	int ans = 0;
	while(j>=0){
		tmp = (str[j]=='0') ? 0 : p;
		ans += tmp;
		p *= 2;
		j--;
	}
	return ans;
}

vector<int> grayCode(int n) {
	vector<int> res;
	vector<string> codes;
	res.push_back(0);
	if(n==0) return res;
	res.push_back(1);
	if(n==1) return res;
	string str = "";
	for(int i=0;i<n-1;i++) str += "0";
	codes.push_back(str+"0");
	codes.push_back(str+"1");
	int len=1;
	while(len<n){
		for(int i=codes.size()-1;i>=0;i--){
			str = codes[i];
			str[n-len-1] = '1';
			codes.push_back(str);
			res.push_back(binary_to_int(str));
		}
		len++;
	}
	// for(int i=0;i<codes.size();i++) cout << codes[i] << " ";
	// 	cout << endl;
	return res;
}

int main(){
	int t;
	cin >> t;
	vector<int> res = grayCode(t);
	for(int i=0;i<res.size();i++) cout << res[i] << " ";
		cout << endl;
	return 0;
}
