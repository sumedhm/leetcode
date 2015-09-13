#include <iostream>

using namespace std;

int climbStairs(int n) {
		int uniquepaths[n+1];
		for(int i=0;i<n+1;i++){
			uniquepaths[i] = 0;
			if(i<=2){
				uniquepaths[i] = i;
				continue;
			}	
			uniquepaths[i] = uniquepaths[i-1] + uniquepaths[i-2];
		}
		return uniquepaths[n];
}

int main(){
	cout << climbStairs(4) << endl;
	return 0;
}