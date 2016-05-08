// Find two repeating elements using XOR

#include <iostream>
#include <vector>

using namespace std;

vector<int> findRepeating(const vector<int> &a) {
	vector<int> res;
	// First do XOR of all the elements present;
	int XOR = a[0];
	for(int i=1;i<a.size();i++)
		XOR = XOR xor a[i];
		
	// Now do XOR with all 1 to n where n = a.size()-2
	int n = a.size()-2;
	for(int i=1;i<=n;i++)
		XOR = XOR xor i;
		
	// Get the rightmost set bit
	// Now since XOR is of the two repeating elements
	// say x ^ y, bit can only be one if they have 
	// different bits at that position
	int setBitNum = XOR & ~(XOR-1);
	int x = 0,y = 0;
	for(int i=0;i<a.size();i++) {
		// Don't set the condition as a[i] & setBitNum
		// since the else condition is always 0 but the
		// truthy condition is not necessarily 1
		if( (a[i] & setBitNum) ) {
			x = x xor a[i];
		} else {
			y = y xor a[i];
		}
	}
	for(int i=1;i<=n;i++) {
		if( (i&setBitNum) ) {
			x = x xor i;
		} else {
			y = y xor i;
		}
	}
	res.push_back(x);
	res.push_back(y);
	return res;
}

int main() {
	vector<int> a = {1,2,2,3,4,4,5};
	vector<int> res = findRepeating(a);
	cout << res[0] << " " << res[1] << "\n";
	return 0;
}
