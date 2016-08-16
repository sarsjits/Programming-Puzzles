// Two Sum Problem: O(n)
// http://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Solution using map
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
	if(twoSum(a,12) == false) {
		cout << "The expected sum can not be obtained.\n";
	} else {
		cout << "The expected sum exists.\n";
	}
	return 0;
}
