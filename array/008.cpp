// Median of two sorted arrays (same size) in O(log n) using Divide and Conquer

#include <iostream>

using namespace std;

// Returns median of the list of numbers
int median(int *a,int n) {
	if( (n&1) == 0 ) {
		return ( (a[n/2] + a[(n/2)-1])/2 );
	} else {
		return a[n/2];
	}
}

int getMedian(int *a,int *b,int n) {
	if(n == 1) {
		return ( (a[0] + b[0])/2 );
	}
	if(n == 2) {
		return ( max(a[0],b[0]) + min(a[1],b[1]) )/2;
	}
	
	int m1 = median(a,n);
	int m2 = median(b,n);
	
	if(m1 == m2)
		return m1;
	if(m1 > m2) {
		if((n&1) == 0)
			return getMedian(b + n/2 - 1,a,n-n/2+1);
		return getMedian(b+n/2,a,n-n/2);
	}
	if((n&1) == 0)
		return getMedian(a+n/2-1,b,n-n/2+1);
	return getMedian(a+n/2,b,n-n/2);
}

int main() {
	int m[] = {1,2,3,6};
	int n[] = {4,6,8,10};
	cout << getMedian(m,n,4);
	cout << "\n";
	return 0;
}
