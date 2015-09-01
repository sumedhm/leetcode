#include <iostream>

using namespace std;

double myPow(double x, int n) {
		if(n==0) return 1;
        if(x==1 || x==0) return x;
        if(x==-1) return ((n%2==0)?1:-1);
        double ans = x;
        bool neg = false;
        if(n<0){
        	neg = true;
        	n = -n;
        }
        for(int i=1;i<n;i++){
        	if(ans==0) return 0;
        	ans *= x;
        }
        if(neg) return 1/ans;
        return ans;
}

int main(){
	cout << myPow(8.88023, 3) << endl;
	return 0;
}