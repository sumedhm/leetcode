#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
	if(numRows==1) return s;
	vector<int> row;
	int num = 1;
	bool increment = true;
	for(int i=0;i<s.length();i++){
		row.push_back(num);
		if(increment){
			num++;
			if(num>numRows){
				num = numRows-1;
				increment = false;
			}
		} else {
			num--;
			if(num<1){
				num = 2;
				increment = true;
			}
		}
		cout << row[i];
	}

	cout << endl;
	string zigzag = "";
	for(int i=1;i<=numRows;i++){
		for(int j=0;j<s.length();j++){
			if(row[j]==i) zigzag += s[j];
		}
	}
	return zigzag;
}

int main(){

	cout << convert("AB",1) << endl;

	return 0;
}