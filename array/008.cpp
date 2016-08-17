/* 
	> Median of two sorted arrays of size n
	> Since the total number of elements would be even, median would be avg of two
	URL: http://bit.ly/17zECdh
*/

#include <iostream>

using namespace std;

/*
	Method 1: Simple counting while merging
	Time: O(1)
	Space: O(1)
*/

int getMedianLinear(int *a,int *b,int n) {
	int i = 0; /* Count for a */
	int j = 0; /* Count for b */
	int count = 0; /* Count for total */
	int med1 = -1, med2 = -1;
	
	for (count = 0; count <= n; count += 1) {
		/*
			Case where all the elements in the array 1 are smaller than in array 2
		*/
		if(i == n) {
			med1 = med2;
			med2 = b[0];
			break;
		} else if(j == n) {
			med1 = med2;
			med2 = a[0];
			break;
		}
		
		if(a[i] < b[i]) {
			med1 = med2;
			med2 = a[i];
			i++;
		} else {
			med1 = med2;
			med2 = b[j];
			j++;
		}
	}
	return (med1 + med2)/2;
}

/*
	Method 2: Using Divide and Conquer
	Time: O(logn)
	Space: 
*/

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
	cout << getMedianLinear(m,n,4);
	cout << "\n";
	return 0;
}
