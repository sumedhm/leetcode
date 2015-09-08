#include <iostream>
#include <string>
#include <vector>

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

void getPermutation_(string& permute, vector<int> fact, int n, int k, vector<char>& list){
	cout << permute << " " << n << "," << k << endl;
	if(n==1){
		permute += list[0];
	}
	if(n==2){
		if(k==1){
			permute += list[0];
			permute += list[1];
			return;
		} else {
			permute += list[1];
			permute += list[0];
			return;
		}
	}
	if(k < fact[n-1]){
		permute += list[0];
		list.erase(list.begin());
		getPermutation_(permute, fact, --n, k, list);
	} else if(k > fact[n-1]){
		for(int j=0;j<list.size();j++){
			if(k < fact[n-1]){
				permute += list[j];
				list.erase(j+list.begin());
				getPermutation_(permute, fact, --n, k, list);
				break;
			} else if(k == fact[n-1]){
				int len = permute.length();
				permute += list[j];
				list.erase(j+list.begin());
				for(int k=0;k<list.size();k++){
					permute += list[k];
				}
				cout << permute << endl;
				permute = reverse(permute, len+1, permute.length()-1);
				break;
			}
			k -= fact[n-1];
		}
	} else if(k == fact[n-1]){
		permute += list[0];
		int len = permute.length();
		list.erase(list.begin());
		for(int k=0;k<list.size();k++){
			permute += list[k];
		}
		permute = reverse(permute, len, permute.length()-1);
	}
	return;
}

string getPermutation(int n, int k) {
		if(n==0) return "";
        if(n==1) return "1";
        string permute = "";
        vector<int> fact;
        vector<char> list;
        fact.push_back(0);
        fact.push_back(1);
        list.push_back('1');
        for(int i=2;i<=n;i++){
        	fact.push_back(i*fact[i-1]);
        	list.push_back(i+'0');
        }
        int f;
		f = k % fact[n];
		if(f!=0) k = f;
		getPermutation_(permute, fact, n, k, list);
        return permute;
}

int main(){
	cout << getPermutation(3, 6) << endl;
	return 0;
}
