// Maximum difference between 2 elements with larger element on right side

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxDiffer(const vector<int> &a) {
	int maxSoFar = a[a.size()-1];
	int maxDiff = 0;
	for(int i=a.size()-2;i>=0;i--) {
		if(maxSoFar < a[i])
			maxSoFar = a[i];
		else {
			int diff = maxSoFar - a[i];
			if(diff > maxDiff)
				maxDiff = diff;
		}
	}
	return maxDiff;
}

int main() {
	vector<int> a = {2,3,10,6,4,8,1};
	cout << maxDiffer(a) << "\n";
	return 0;
}
