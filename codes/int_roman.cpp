#include <iostream>

using namespace std;

string intToRoman(int num) {

		string ans = "";
		int unit = num%10;
		num /= 10;
		if(unit<=3){
			for(int i=0;i<unit;i++){
				ans += "I";
			}
		} else if(unit==4){
			ans += "IV";
		} else if(unit<9){
			ans += "V";
			for(int i=0;i<unit-5;i++){
				ans += "I";
			}
		} else if(unit==9){
			ans += "IX";
		} else {
			//do nothing.
		}
		int ten = num%10;
		num /= 10;
		if(ten<=3){
			for(int i=0;i<ten;i++){
				ans = "X" + ans;
			}
		} else if(ten==4){
			ans = "XL" + ans;
		} else if(ten<9){
			for(int i=0;i<ten-5;i++){
				ans = "X" + ans;
			}
			ans = "L" + ans;
		} else if(ten==9){
			ans = "XC" + ans;
		} else {
			//do nothing.
		}
		int hundred = num%10;
		num /= 10;
        if(hundred<=3){
			for(int i=0;i<hundred;i++){
				ans = "C" + ans;
			}
		} else if(hundred==4){
			ans = "CD" + ans;
		} else if(hundred<9){
			for(int i=0;i<hundred-5;i++){
				ans = "C" + ans;
			}
			ans = "D" + ans;
		} else if(hundred==9){
			ans = "CM" + ans;
		} else {
			//do nothing.
		}
		for(int i=0;i<num;i++){
			ans = "M" + ans;
		}
		return ans;
}

int main(){
	cout << intToRoman(1876) << endl;
	return 0;
}