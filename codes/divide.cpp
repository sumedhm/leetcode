#include <iostream>

using namespace std;

int divide(int dividend, int divisor){
	if(divisor==1) return dividend;
	if(dividend<divisor) return 0;
	int ans = 0, shifts = 0;
	int sign = (dividend<0) ? -1 : 1;
	sign = sign * ((divisor<0) ? -1 : 1);
	if(dividend<0) dividend = -dividend;
	if(divisor<0) divisor = -divisor;
	while(dividend>=divisor){
		shifts = 0;
		while(dividend>=(divisor<<shifts)){
			shifts++;
		}
		ans += 1<<(shifts-1);
		dividend = dividend - (divisor<<(shifts-1));
	}
   	return (sign==1) ? ans : -ans;
}

int main(){

	cout << divide(10,2) << endl;
	return 0;
}