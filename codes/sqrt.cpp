#include <iostream>

using namespace std;

int mySqrt(int x) {
        int s = 0, p = 0;
        while(p<=x){
        	s++;
        	if(s==46350) return s;
        	p = s*s;
        }
        return s-1;
}

int main(){
	cout << mySqrt(1579205274) << endl;
	return 0;
}