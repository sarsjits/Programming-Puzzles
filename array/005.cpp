// Largest sum contiguous sub array using Kadanne's algorithm

#include <iostream>
#include <vector>

using namespace std;

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

int main() {
	vector<int> a = {-2,-3,4,-1,-2,1,5,-3};
	cout << largestSum(a) << "\n";
	return 0;
}
