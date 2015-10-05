#include <iostream>
#include <vector>

using namespace std;

bool se(vector<int> A, int st, int ed, int target){
	if (st>ed) {return false;}
    else{
        int mid = st+(ed-st)/2;
        if (A[mid]==target){return true;}
         
        if (A[mid]>A[st]){
            if (target<=A[mid] && target>=A[st]){
                return se(A,st,mid-1,target);
            }else{
                return se(A,mid+1,ed,target);
            }
        }
         
        if (A[mid]<A[st]){
             
            if (target<=A[mid] || target >= A[st]){
                return se(A,st,mid-1,target);
            }else{
                return se(A,mid+1,ed,target);
            }
             
        }
         
        if (A[mid]==A[st]){return se(A,st+1,ed,target);}
         
        return false;
    }
}

bool search(vector<int>& nums, int target) {
	if(nums.size()==0) return false;
	return se(nums, 0, nums.size()-1, target);
}

int main(){
	int arr[] = {9,10,11,2,3,6,8};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	int in;
	while(true){		
		cin >> in;
		cout << search(nums, in) << endl;
	}
	return 0;
}