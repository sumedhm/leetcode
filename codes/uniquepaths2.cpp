#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n) {
		if(m==0 || n==0) return 0;
        if(m==1 || n==1) return 1;
        return (uniquePaths(m-1, n) + uniquePaths(m, n-1));
}

int main(){
	cout << uniquePaths(23,12) << endl;
	return 0;
}