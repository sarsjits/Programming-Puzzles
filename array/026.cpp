// Maximum element in the array which is first increasing and then decreasing

#include <iostream>
#include <vector>

using namespace std;

int _findMax(const vector<int> &a,int low,int high) {
	if(low == high)
		return low;
	if(high == low+1) {
		if(a[low] > a[high])
			return low;
		else 
			return high;
	}
	int mid = low + (high-low)/2;
	if(a[mid] > a[mid+1] && a[mid] > a[mid-1])
		return mid;
	else if(a[mid]>a[mid+1] && a[mid]<a[mid-1])
		return _findMax(a,low,mid-1);
	else if(a[mid]<a[mid+1] && a[mid]>a[mid-1])
		return _findMax(a,mid+1,high);
}

int findMax(const vector<int> &a) {
	if(a.size() == 0)
		return -1;
	return _findMax(a,0,a.size()-1);
}

int main() {
	vector<int> a = {1,2,3,4,5,3,2,1};
	cout << findMax(a) << "\n";
	return 0;
}
