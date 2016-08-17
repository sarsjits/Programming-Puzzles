/*
	Search an element in sorted and pivoted array-
	assuming no duplicates are allowed.
	URL:
*/

#include <iostream>
#include <vector>

using namespace std;

/*
	Method 1: Uses three pass binary search
	Time Complexity: O(logn)
	Space Complexity: O(1)
*/

// returns index of pivot, if no pivot returns -1
int findPivot(vector<int> &a,int low,int high) {
	while(low<=high) {
		int mid = low + (high-low)/2;
		if(mid<high && a[mid]>a[mid+1])
			return mid;
		if(mid>low && a[mid]<a[mid-1])
			return mid-1;
		if(a[mid] < a[low])
			high = mid - 1;
		else 
			low = mid + 1;
	}
	return -1;
}

// generic binary search
int binarySearch(vector<int> &a,int low,int high,int key) {
	while(low <= high) {
		int mid = low + (high-low)/2;
		if(a[mid] == key) 
			return mid;
		if(a[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

// returns index if found, else -1
int searchInPivoted(vector<int> &a,int key) {
	int pivotIdx = findPivot(a,0,a.size()-1);
	// condition where there is no pivot and the key
	// can be searched as if the array is completely sorted
	if(pivotIdx == -1) {
		return binarySearch(a,0,a.size()-1,key);
	}
	if(key > a[pivotIdx])
		return -1;
	else if(key >= a[0]) {
		return binarySearch(a,0,pivotIdx,key);
	} else {
		return binarySearch(a,pivotIdx+1,a.size()-1,key);
	}
}

/*
	Method 2: Use one pass binary search
	Time: O(logn)
	Space: O(1)
*/

int searchMain(vector<int> &a, int low, int high, int key) {
	if(low > high) return -1;
	int mid = low + (high-low)/2;
	
	if(a[mid] == key) return mid;
	
	if(a[low] <= a[mid]) {
		if(key >= a[low] && key <= a[mid]) 
			return searchMain(a,low,mid-1,key);
		return searchMain(a,mid+1,high,key);
	}
	
	if(key >= a[mid] && key <= a[high])
		return searchMain(a,mid+1,high,key);
	return searchMain(a,low,mid-1,key);
}

int search(vector<int> &a, int key) {
	return searchMain(a,0,a.size()-1,key);
}

int main() {
	vector<int> a = {3,4,5,1,2};
	cout << search(a,6) << "\n";
	return 0;
}
