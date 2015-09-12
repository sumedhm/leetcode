#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) {
		string sum = "";
        int i = a.length()-1;
        int j = b.length()-1;
        bool carry = false;
        while(i>=0 && j>=0){
        	if(a[i]=='1'){
        		if(b[j]=='1'){
        			if(carry){
        				sum = '1' + sum;
        			} else {
        				sum = '0' + sum;
        				carry = true;
        			}
        		} else {
        			if(carry){
        				sum = '0' + sum;
        			} else {
        				sum = '1' + sum;
        			}
        		}
        	} else {
        		if(b[j]=='1'){
        			if(carry){
        				sum = '0' + sum;
        			} else {
        				sum = '1' + sum;
        			}
        		} else {
        			if(carry){
        				sum = '1' + sum;
        				carry = false;
        			} else {
        				sum = '0' + sum;
        			}
        		}
        	}
        	i--; j--;
        }
        while(i>=0){
        	if(a[i]=='1'){
        		if(carry){
        			sum = '0' + sum;        			
        		} else {
        			sum = '1' + sum;
        			carry = false;
        		}
        	} else {
        		if(carry){
        			sum = '1' + sum;
        			carry = false;      			
        		} else {
        			sum = '0' + sum;
        		}
        	}
        	i--;
        }
        while(j>=0){
        	if(b[j]=='1'){
        		if(carry){
        			sum = '0' + sum;        			
        		} else {
        			sum = '1' + sum;
        			carry = false;
        		}
        	} else {
        		if(carry){
        			sum = '1' + sum;
        			carry = false;      			
        		} else {
        			sum = '0' + sum;
        		}
        	}
        	j--;
        }
        if(carry) return ('1'+sum);
        return sum;
}

int main(){
	cout << addBinary("111", "1010") << endl;
	return 0;
}