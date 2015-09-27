#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
        int p0=0, p2=nums.size()-1;
        while(p0<=p2 && nums[p0]==0) p0++;
        if(p0>p2) return;
        while(p2>p0 && nums[p2]==2) p2--;
        if(p2<=p0) return;
        int j = p2;
        for(int i=p0;p0<p2 && i<=p2;i++){
	        // cout << p0 << "," << p2 << "," << i << endl;
        	if(nums[i]==1) continue;
        	if(nums[i]==0){
        		nums[i] = nums[p0];
        		nums[p0] = 0;
        		p0++;
        		while(nums[p0]==0) p0++;
        	} else {
        		nums[i] = nums[p2];
        		if(nums[p2]==0) i--;
        		nums[p2] = 2;
        		p2--;
        		while(nums[p2]==2) p2--;
        	}
        }
        return;

}

int main(){
	int arr[] = {2,2,1,1,1,1,1,0,2,0};
	vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
	sortColors(nums);
	for(int i=0;i<nums.size();i++) cout << nums[i] << " ";
	cout << endl;
	return 0;
}