// Find the number occurring odd number of time in O(n) using XOR

#include <iostream>
#include <vector>
using namespace std;

int findOdd(vector<int> &a) {
	int res = 0;
	for(int i=0;i<a.size();i++) {
		res = res xor a[i];
	}
	return res;
}

int main() {
	vector<int> a = {1,1,0,0,2,3,3,3,3,4,4,4,4,4,4};
	cout << findOdd(a) << "\n";
	return 0;
}
