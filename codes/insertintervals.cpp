#include <iostream>
#include <vector>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

void quickSort(vector<Interval>& arr, int left, int right){
	int i = left, j = right, pivot = arr[(left+right)/2].start;
	Interval temp;
	while(i<=j){
		while(arr[i].start<pivot) i++;
		while(arr[j].start>pivot) j--;
		if(i<=j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++; j--;
		}
	}
	if(j>left) quickSort(arr, left, j);
	if(i<right) quickSort(arr, i, right);
	return;
}

bool intersect(Interval i1, Interval i2){
	if(i1.end>=i2.start) return true;
	return false;
}

vector<Interval> merge(vector<Interval>& intervals) {
		if(intervals.size()<=1) return intervals;
		vector<Interval> merged;
		Interval cur = intervals[0];
		for(int i=1;i<intervals.size();i++){
			if(intersect(cur, intervals[i])){
				cur = Interval(min(cur.start, intervals[i].start), max(cur.end, intervals[i].end));
			} else {
				merged.push_back(cur);
				cur = intervals[i];
			}
		}
		merged.push_back(cur);
        return merged;
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.size()==0){
        	vector<Interval> temp;
        	temp.push_back(newInterval);
        	return temp;
        }
        quickSort(intervals,0,intervals.size()-1);
        int i;
        for(i=0;i<intervals.size();i++){
        	if(newInterval.start<intervals[i].start) break;
        }
        intervals.insert(i+intervals.begin(), newInterval);
        return merge(intervals);
}

int main(){
	Interval arr[] = {Interval(1,2), Interval(3,5), Interval(6,7), Interval(8,10), Interval(12,16)};
	vector<Interval> intervals(arr, arr+sizeof(arr)/sizeof(Interval));
	intervals = insert(intervals, Interval(4,9));
	for(int i=0;i<intervals.size();i++){
		cout << intervals[i].start << " " << intervals[i].end << endl;
	}
	return 0;
}