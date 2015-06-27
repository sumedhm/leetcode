#include <iostream>
#include <vector>

using namespace std;

int maximum(int a, int b){
	return ((a>b) ? a : b);
}

int minimum(int a, int b){
	return ((a<b) ? a : b);
}

double medianof3(int a, int b, int c){
	int min = minimum(a, minimum(b,c));
	int max = maximum(a, maximum(b,c));
	return (a+b+c-min-max);
}

double medianof4(int a, int b, int c, int d){
	int max = maximum(a, maximum(b, maximum(c,d)));
	int min = minimum(a, minimum(b, minimum(c,d)));
	return (double)(a+b+c+d-max-min)/2;
}

double medianSortedArrays(vector<int>& nums1, vector<int>& nums2, int l1, int r1, int l2, int r2){
cout << "0-l1-" << l1 << ",r1-" << r1 << ",l2-" << l2 << ",r2-" << r2 << "===" << endl;
	if(l1>r1) nums1.clear();
	if(l2>r2) nums2.clear();
	int n = r1+1-l1;
	int m = r2+1-l2;
	if(nums1.size()==0) n = 0;
	if(nums2.size()==0) m = 0;
	cout << n << "," << m << endl;
	if(m<n){
		cout << "swapped" << endl;
		nums1.swap(nums2);
		int temp = m;
		m = n;
		n = temp;
		temp = l1;
		l1 = l2;
		l2 = temp;
		temp = r1;
		r1 = r2;
		r2 = temp;
	}
	if(n==0){
		int x = (r2-l2+1)/2;
		if(m%2==0){
			return (double)(nums2[x]+nums2[x-1])/2;
		} else {
			cout << "," << nums2[x] << "," << x << endl;
			return nums2[x];
		}
	}
	else if(n==1){
		if(m==1){
			cout << "1-l1-" << l1 << ",r1-" << r1 << ",l2-" << l2 << ",r2-" << r2 << "===" << endl;
			return (double)(nums1[l1]+nums2[l2])/2;
		}
		else if(m==2){
			cout << "2-l1-" << l1 << ",r1-" << r1 << ",l2-" << l2 << ",r2-" << r2 << "===" << endl;
			return medianof3(nums1[l1],nums2[l2], nums2[r2]);
		}
		else {
			int x = (r2-l2+1)/2 + l2;
			if(m%2==0){
				cout << "3-l1-" << l1 << ",r1-" << r1 << ",l2-" << l2 << ",r2-" << r2 << "===" << endl;
				if(nums1[l1]<nums2[x-1]) return nums2[x-1];
				else if(nums1[l1]>nums2[x]) return nums2[x];
				else return nums1[l1];
			} else {
				cout << "4-l1-" << l1 << ",r1-" << r1 << ",l2-" << l2 << ",r2-" << r2 << "===" << x << endl;
				if(nums1[l1]<nums2[x-1]) return (double)(nums2[x-1]+nums2[x])/2;
				else if(nums1[l1]>nums2[x+1]) return (double)(nums2[x]+nums2[x+1])/2;
				else return (double)(nums2[x]+nums1[l1])/2;
			}
		}
	} else if(n==2){
		if(m==2){
			cout << "5-l1-" << l1 << ",r1-" << r1 << ",l2-" << l2 << ",r2-" << r2 << "===" << endl;
			return medianof4(nums1[l1], nums1[r1], nums2[l2], nums2[r2]);
		} else {
			int x = (r2-l2+1)/2 + l2;
			if(m%2==0){
				cout << "6-l1-" << l1 << ",r1-" << r1 << ",l2-" << l2 << ",r2-" << r2 << "===" << endl;
				return medianof4(nums2[x-1], nums2[x], maximum(nums1[l1], nums2[x-2]), minimum(nums2[x+1], nums1[r1]));
			} else {
				cout << "7-l1-" << l1 << ",r1-" << r1 << ",l2-" << l2 << ",r2-" << r2 << "===" << x << endl;
				return medianof3(nums2[x], maximum(nums1[l1], nums2[x-1]), minimum(nums1[r1], nums2[x+1]));
			}
		}
	} else {
		int x,y;
		if(n%2==1){
			x = (r1-l1)/2;
			y = (r2-l2)/2;
		} else {
			x = (r1-l1+1)/2;
			y = (r2-l2+1)/2;
		}
		if(nums1[l1+x]>nums2[l2+y]){
			cout << "8-l1-" << l1 << ",r1-" << r1 << ",l2-" << l2 << ",r2-" << r2 << "l1+x-" << l1+x << "l2+y-" << l2+y << endl;
			return medianSortedArrays(nums1, nums2, l1, l1+x, l2+r1-l1-x, r2);
		} else {
			cout << "9-l1-" << l1 << ",r1-" << r1 << ",l2-" << l2 << ",r2-" << r2 << "l1+x-" << l1+x << "l2+y-" << l2+y << "==" << y << endl;
			return medianSortedArrays(nums1, nums2, l1+x, r1, l2, r2-x);
		}
	}

}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){

	return medianSortedArrays(nums1, nums2, 0, nums1.size()-1, 0, nums2.size()-1);

}

int main(){

	int nums1[] = {1,4,5,6};
	int nums2[] = {2,3,7,8};
	vector<int> v1(nums1, nums1 + sizeof(nums1) / sizeof(int));
	vector<int> v2(nums2, nums2 + sizeof(nums2) / sizeof(int));
	float a = findMedianSortedArrays(v1, v2);

	cout << a << endl;
	return 0;
}


 