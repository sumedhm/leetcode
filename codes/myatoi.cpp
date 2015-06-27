#include <iostream>
#include <string>

using namespace std;

int myAtoi(string str){

	int ans = 0;
	for(int i=0;i<str.length();i++)	{
		ans = ans*10 + (str[i]-'0');
	}
	return ans;
}

int main(){

	cout << myAtoi("123") << endl;
	return 0;
}