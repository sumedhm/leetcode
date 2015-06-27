#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int reverse(int x) {
	if(x==0) return 0;
	int neg = x/abs(x);
	x = abs(x);
	int rev = 0;
	int rem;
	while(x>0){
		rem = x%10;
		if(rev>214748364 || (rev==214748364 && rem>7)) return 0;
		rev = rev*10 + rem;
		x /= 10;
	}
	return rev*neg;
}

bool isPalindrome(int x) {
	if(x<0) return false;
	return (x==reverse(x));
}

int main(){

	cout << isPalindrome(-2147447412) << endl;

	return 0;

}