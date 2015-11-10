#include <iostream>

using namespace std;

int numTrees(int n) {
	int bst[n+1];
	bst[0] = 1;
	bst[1] = 1;
	bst[2] = 2;   
	for(int i=3;i<=n;i++){
		bst[i] = 0;
		for(int j=0;j<=i-1;j++){
			bst[i] += bst[j]*bst[i-1-j];
		}
 	}
	return bst[n];
}

int main(){
	int n;
	cin >> n;
	cout << numTrees(n) << endl;
	return 0;
}
