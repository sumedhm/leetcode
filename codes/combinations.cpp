#include <iostream>
#include <vector>

using namespace std;

void combineuptok(vector<vector<int> >& ans, int arr[], int n, vector<int>& temp, int i, int k){
	if(temp.size() >= k){
		ans.push_back(temp);
		return;
	} else {
		for(int j=i;j<n;j++){
			temp.push_back(arr[j]);
			combineuptok(ans, arr, n, temp, j+1, k);
			temp.pop_back();
		}
	}
	return;
}

vector<vector<int> > combine(int n, int k) {
	vector<vector<int> > ans;
	if(k==0 || n==0) return ans;
	int arr[n];
	for(int i=0;i<n;i++){
		arr[i] = i+1;
	}
    vector<int> temp;
    combineuptok(ans, arr, n, temp, 0, k);
    return ans;
}

int main(){
	int n=4,k=2;
	vector<vector<int> > ans = combine(n,k);
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}