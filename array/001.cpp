/* Two Sum Problem
	URL: http://bit.ly/1fOtbzi
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/*
	Methode 1: Using Sorting.
	Time Complexity: O(n*logn)
*/

bool twoSumSorting(vector<int> &a, int x) {
	int start = 0;
	int end = a.size() - 1;
	sort(a.begin(),a.end());
	while(start<end) {
		if(a[start] + a[end] == x) return true;
		else if(a[start] + a[end] < x) start++;
		else end--;
	}
	return false;
}

/*
	Method 2: Using Map
	Time Complexity: O(n)
*/
bool twoSum(vector<int>& a,int x) {
	map<int,int> hmap;
	for(int i=0;i<a.size();i++) {
		hmap[a[i]] = i;
	}
	for(int i=0;i<a.size();i++) {
		// hmap[x-a[i]] != i is a case in which the map may return the same index.
		if(hmap.find(x-a[i]) != hmap.end() && hmap[x-a[i]] != i) {
			return true;
		}
	}
	return false;
}

int main() {
	vector<int> a = {6,4,2,3,1,5};
	if(twoSumSorting(a,12) == false) {
		cout << "The expected sum can not be obtained.\n";
	} else {
		cout << "The expected sum exists.\n";
	}
	return 0;
}
