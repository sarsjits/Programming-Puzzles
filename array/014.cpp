// check if given number is a majority element in sorted array O(log n)

#include <iostream>
#include <vector>

using namespace std;

// Returns the last occurrence of the element in the array
int last(vector<int> &a,int low,int high,int key) {
	while(high - low > 1) {
		int mid = low + (high - low)/2;
		if(a[mid] <= key)
			low = mid;
		else
			high = mid;
	}
	if(a[low] == key)
		return low;
	else
		return -1;
}

int first(vector<int> &a,int low,int high,int key) {
	while(high - low > 1) {
		int mid = low + (high-low)/2;
		if(a[mid] >= key)
			high = mid;
		else
			low = mid;
	}
	if(a[high] == key)
		return high;
	else
		return -1;
}

bool isMajority(vector<int> &a, int key) {
	int x = first(a,0,a.size(),key);
	int y = last(a,0,a.size(),key);
	if(y-x+1 > a.size()/2)
		return true;
	return false;
}

int main() {
	vector<int> a = {1,2,2,2,2,2,3,3,3};
	if(isMajority(a,3) == true)
		cout << "Majority\n";
	else
		cout << "Not majority\n";
	return 0;
}
