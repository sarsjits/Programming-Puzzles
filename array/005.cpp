/*
	Largest sum contiguous sub array using Kadanne's algorithm
	URL: http://bit.ly/1ZDmgwx
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

/*
	Method 1: Does not handle case where all the numbers are negative
*/
int largestSum(vector<int> &a) {
	int maxSoFar = 0;
	int maxEndingHere = 0;
	for(int i=0;i<a.size();i++) {
		maxEndingHere += a[i];
		if(maxEndingHere < 0)
			maxEndingHere = 0;
		if(maxSoFar < maxEndingHere)
			maxSoFar = maxEndingHere;
	}
	return maxSoFar;
}

/*
	Method 2: Handles case where all numbers are negative
	Time and space complexity remains the same
*/

int lContSum(vector<int> &a) {
	int maxSoFar = a[0];
	int curMax = a[0];
	for(auto curVal : a) {
		curMax = max(curVal,curMax + curVal);
		maxSoFar = max(curMax,maxSoFar);
	}
	return maxSoFar;
}

int main() {
	vector<int> a = {-2,-3,-4,-1,-2,-1,-5,-3};
	cout << lContSum(a) << "\n";
	return 0;
}
