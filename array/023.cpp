// Find index of 0 to be flipped to get longest continuous sequence of 1s

#include <iostream>
#include <vector>

using namespace std;

int getMaxOnes(vector<int> &a) {
	int maxCount=0;
	int maxIdx=0;
	int prevZero=-1;
	int prevPrevZero=-1;
	for(int curr=0;curr<a.size();curr++) {
		if(a[curr] == 0) {
			if(curr - prevPrevZero > maxCount) {
				maxCount = curr - prevPrevZero;
				maxIdx = prevZero;
			}
			prevPrevZero = prevZero;
			prevZero = curr;
		}
	}
	if(a.size() - prevPrevZero > maxCount) {
		maxIdx = prevZero;
	}
	return maxIdx;	
}

int main() {
	vector<int> a = {0,1,1,1,1,0};
	vector<int> b = {0,1,0,1,1,0,1,1,1,0,1,1};
	vector<int> c = {1,1,1,0,1,1,1,0,1,1,1,1,0};
	cout << getMaxOnes(c) << "\n";
	return 0;
}
