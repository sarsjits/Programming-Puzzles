/*
	Find the minimum element in the sorted and rotated array, No duplicates allowed
	URL: http://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
	Tests:
	1) 5,6,1,2,3,4
	2) 1,2,3,4
	3) 2,1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	Method 1: Using binary search
	Time: O(logn)
	Space: O(1)
*/

int _findMin(vector<int> &a, int low, int high) {
	if(high < low) return a[0];
	if(high == low) return a[low];
	
	int mid = low + (high - low)/2;
	if(mid < high && a[mid+1] < a[mid]) return a[mid+1];
	if(mid > low && a[mid] < a[mid-1]) return a[mid];
	if(a[high] > a[mid]) 
		return _findMin(a,low,mid-1);
	return _findMin(a,mid+1,high);
}

int findMin(vector<int> &a) {
	_findMin(a,0,a.size()-1);
}

int main (int argc, char const* argv[])
{
	vector<int> a = {5,6,1,2,3,4};
	cout << findMin(a) << "\n";
	return 0;
}
