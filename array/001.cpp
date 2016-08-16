/* Two Sum Problem
	URL: http://bit.ly/1fOtbzi
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
	Method 1: Using Map
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
	vector<int> a = {1,2,3,4,5,6};
	if(twoSum(a,11) == false) {
		cout << "The expected sum can not be obtained.\n";
	} else {
		cout << "The expected sum exists.\n";
	}
	return 0;
}
