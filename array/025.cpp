// Tournament method to find min max in minimum number of comparisons

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct pair_minmax {
	int min;
	int max;
};

pair_minmax findMinMax(const vector<int> &a,int low,int high) {
	pair_minmax minmax,mmr,mml;
	if(low == high) {
		minmax.min = a[low];
		minmax.max = a[low];
		return minmax;
	}
	if(high == low+1) {
		if(a[low] < a[high]) {
			minmax.min = a[low];
			minmax.max = a[high];
		} else {
			minmax.min = a[high];
			minmax.max = a[low];
		}
		return minmax;
	}
	
	int mid = low + (high-low)/2;
	mml = findMinMax(a,low,mid);
	mmr = findMinMax(a,mid+1,high);
	
	if(mml.min < mmr.min) {
		minmax.min = mml.min;
	} else {
		minmax.min = mmr.min;
	}
	
	if(mml.max > mmr.max) {
		minmax.max = mml.max;
	} else {
		minmax.max = mmr.max;
	}
	
	return minmax;
}

int main() {
	vector<int> a = {1,2,3,4,5,6,7,8};
	pair_minmax p = findMinMax(a,0,a.size()-1);
	cout << p.min << " " << p.max << "\n";
	return 0;
}
