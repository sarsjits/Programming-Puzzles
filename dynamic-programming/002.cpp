// Longest Increasing Subsequence using dynamic programming

#include <iostream>
#include <vector>

using namespace std;

int LIS(const vector<int> &a) {
	int n = a.size();
	int *lis = new int [n];
	// Since minimum length would surely be 1
	// So initialize the length in lis array to be 1 for all
	for(int i=0;i<n;i++)
		lis[i] = 1;
	
	// calculating lis array for each element
	for(int i=1;i<n;i++) {
		for(int j=0;j<i;j++) {
			if(a[j]<a[i] && lis[i] < lis[j]+1)
				lis[i] = lis[j] + 1;
		}
	}
	
	// max in lis array will be the answer
	int max = lis[0];
	for(int i=1;i<n;i++) {
		if(max < lis[i])
			max = lis[i];
	}
	
	delete [] lis;
	return max;
}

int main() {
	vector<int> a = {10,22,9,33,21,50,41,60};
	cout << LIS(a) << "\n";
	return 0;
}
