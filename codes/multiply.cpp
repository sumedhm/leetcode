#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string add(string num1, string num2){
	stringstream ans("");
	string temp;
	int carry = 0, sum = 0;
	int i=num1.length()-1, j=num2.length()-1;
	while(i>=0 && j>=0){
		sum = (num1[i]-'0') + (num2[j]-'0') + carry;
		if(sum>=10){
			sum = sum%10;
			carry = 1;
		} else {
			carry = 0;
		}
		temp = ans.str();
		ans.str("");
		ans << sum << temp;
		i--; j--;
	}
	while(i>=0){
		sum = (num1[i]-'0') + carry;
		if(sum>=10){
			sum = sum%10;
			carry = 1;
		} else {
			carry = 0;
		}
		temp = ans.str();
		ans.str("");
		ans << sum << temp;
		i--;
	}
	while(j>=0){
		sum = (num2[j]-'0') + carry;
		if(sum>=10){
			sum = sum%10;
			carry = 1;
		} else {
			carry = 0;
		}
		temp = ans.str();
		ans.str("");
		ans << sum << temp;
		j--;
	}
	if(carry!=0){
		temp = ans.str();
		ans.str("");
		ans << 1 << temp;
	}
	return ans.str();
}

string product(string num1, char num2){
	cout << ":" << num1 << " " << num2 << endl;
	stringstream ans("");
	string temp; int prod;
	int n1, n2 = num2-'0';
	int carry = 0;
	for(int i=num1.length()-1;i>=0;i--){
		n1 = num1[i]-'0';
		prod = n1*n2 + carry;
		if(prod>=10){
			carry = prod/10;
			prod = prod%10;
		} else {
			carry = 0;
		}
		temp = ans.str();
		ans.str("");
		ans << prod << temp;
	}
	if(carry!=0){
		temp = ans.str();
		ans.str("");
		ans << carry << temp;
	}
	return ans.str();
}

string multiply(string num1, string num2){
	if(num1=="0" || num2=="0") return "0";
	string sum = "0"; string append = "";
	string prod;
	for(int j=num2.length()-1;j>=0;j--){
			prod = product(num1, num2[j]) + append;
			append += "0";
			cout << sum << " " << prod << endl;
			sum = add(sum ,prod);
	}
	return sum;
}

int main(){
	cout << multiply("123","456") << endl;
	return 0;
}