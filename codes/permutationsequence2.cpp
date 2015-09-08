#include <iostream>
#include <string>

using namespace std;

string reverse(string permutation, int left, int right){
	if(left>=right) return permutation;
	char tmp;
	while(left<right){
		tmp = permutation[left];
		permutation[left] = permutation[right];
		permutation[right] = tmp;
		left++; right --;
	}
	return permutation;
}

string nextPermutation(string prevPermutation){
	int i, swap;
	for(i=prevPermutation.length()-1;i > 0;i--){
		if(prevPermutation[i]>prevPermutation[i-1]) break;
	}
	i -= 1;
	if(i==-1){
		return reverse(prevPermutation,0,prevPermutation.length()-1);
	}
	for(int j=prevPermutation.length()-1;j>=i+1;j--){
		if(prevPermutation[j]>prevPermutation[i]){
			swap = j;
			break;
		}
	}
	char tmp = prevPermutation[i];
	prevPermutation[i] = prevPermutation[swap];
	prevPermutation[swap] = tmp;
	return reverse(prevPermutation,i+1,prevPermutation.length()-1);
}

int factorial(int n){
	if(n<=2) return n;
	else return (n*factorial(n-1));
}

string getPermutation(int n, int k) {
		k = k % factorial(n);
		if(n==0) return "";
        if(n==1) return "1";
        string permute = "";
        for(int i=1;i<=n;i++){
        	permute += (char)(i+'0');
        }
        for(int i=1;i<k;i++){
        	// cout << permute << endl;
        	permute = nextPermutation(permute);
        }
        return permute;
}

int main(){
	cout << getPermutation(8, 128) << endl;
	return 0;
}
