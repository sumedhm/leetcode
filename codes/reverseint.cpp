#include <iostream>
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

int main(){

	cout << reverse(1534236469) << endl;
	return 0;
}