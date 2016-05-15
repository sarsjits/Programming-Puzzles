// Count sum of digits from 1 to n
// http://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/
// http://math.stackexchange.com/questions/817038/sum-of-digits-of-number-from-1-to-n/817080#817080

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int sumOfDigits(int num) {
	if(num < 10) {
		return ((num)*(num+1))/2;
	}
	// for 328 it would be 2
	int d = log10(num);
	
	int dp[d+1];
	dp[0] = 0;
	dp[1] = 45;
	for(int i=2;i<=d;i++) {
		dp[i] = dp[i-1]*10 + 45*(ceil(pow(10,i-1)));
	}
	// calculating 10^d
	int p = ceil(pow(10,d));
	// most significant digit
	int msd = num/p;
	
	return msd*dp[d] + (((msd-1)*(msd))/2)*p + msd*(1+num%p) + sumOfDigits(num%p);
}

int main() {
	int num = 328;
	cout << sumOfDigits(num) << "\n";
	return  0;
}
