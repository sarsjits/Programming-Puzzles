/*
	Maximum Product Subarray
	Tests:
	1) {6, -3, -10, 0, 2}
	2) {-1, -3, -10, 0, 60}
	3) {-2, -3, 0, -2, -40}
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

/*
	Method 1: max(max product forward,max product backward)
	Time: O(n)
	Space: O(1)
*/

int maxProdArray(vector<int> &a) {
	int maxForward = numeric_limits<int>::lowest();
	int maxBackward = numeric_limits<int>::lowest();
	int cur = 1;
	for(auto val : a) {
		cur *= val;
		if(cur == 0) {
			cur = 1; continue;
		}
		if(maxForward < cur)
			maxForward = cur;
	}
	cur = 1;
	for(auto val : a) {
		cur *= val;
		if(cur == 0) {
			cur = 1; continue;
		}
		if(maxBackward < cur)
			maxBackward = cur;
	}
	return max(maxForward,maxBackward);
}

int main (int argc, char const* argv[])
{
	vector<int> a = {6, -3, -10, 0, 2};
	cout << maxProdArray(a) << "\n";
	return 0;
}
