/* 
	Merge one array of size n into another of size m+n
	URL: http://bit.ly/2bmHwY6
*/

#include <iostream>
#include <vector>

#define NA -1

using namespace std;


// This function moves all m elements of mPlusN to end of array
void shiftToEnd(vector<int> &mPlusN) {
	int i = mPlusN.size() - 1;
	int j = i;
	for(;i>=0;i--) {
		if(mPlusN[i] != NA) {
			mPlusN[j] = mPlusN[i];
			j--;
		}
	}
}

void merge(vector<int> &mPlusN, vector<int> &N) {
	int n = N.size();
	int m = mPlusN.size() - n;
	int i = n; // starting index for mPlusN
	int j = 0; // starting index of N
	int k = 0; // index needed at the time of filling the array
	while(k < m+n) {
		if( (i < m+n && mPlusN[i] < N[j]) || j == n ) {
			mPlusN[k] = mPlusN[i];
			i++;
		} else {
			mPlusN[k] = N[j];
			j++;
		}
		k++;
	}
}

void print(vector<int> &a) {
	for(int i=0;i<a.size();i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

int main() {
	vector<int> mPlusN = {1,NA,3,NA,5,NA};
	vector<int> N = {2,4,6};
	shiftToEnd(mPlusN);
	merge(mPlusN,N);
	print(mPlusN);
	return 0;
}
