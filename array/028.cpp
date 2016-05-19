// If any two intervals overlap

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
};

bool comp(Interval a,Interval b) {
	return a.start < b.start;
}

bool isOverlapping(vector<Interval>& arr) {
	if(arr.size() == 0)
		return false;
	// Step 1: Sort the interval on the basis of start time
	sort(arr.begin(),arr.end(),comp);
	// Step 2: Check for overlaps by checking if the end time
	// of one interval is overlaping with the start time 
	// of the next interval
	for(int i=0;i<arr.size()-1;i++) {
		if(arr[i].end > arr[i+1].start)
			return true;
	}
	return false;
}

int main() {
	vector<Interval> arr = {{1,9},{2,4},{5,8}};
	if(isOverlapping(arr) == true)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
