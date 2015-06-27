#include <iostream>
#include <string>

using namespace std;

int myAtoi(string str){

		int ans = 0;
		int i=0;
		int neg=0;
		while(str[i]==' ') i++;
		if(str[i]=='+'){
			neg=0;
			i++;
		}
		else if(str[i]=='-'){
			neg = 1;
			i++;
		}
		for(i=i;i<str.length();i++)	{
			if(str[i]<'0' || str[i]>'9') break;
			if(ans>214748364 || (ans==214748364 && (str[i]-'0')>7)) return (2147483647+neg);
			ans = ans*10 + (str[i]-'0');
		}
		return ans*((neg==0)? 1:-1);
}

int main(){

	cout << myAtoi("-1") << endl;
	return 0;
}