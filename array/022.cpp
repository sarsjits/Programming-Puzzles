// Maximum profit by buying and selling a share at most twice

#include <iostream>
#include <vector>

using namespace std;

/*
Understanding the below algorithm would be the best thing to do

Let's take the array as 

Array => 			[ 2 , 30 , 15 , 10 , 8 , 25 , 80 ]

Index =>				[ 0 , 1 , 2 , 3 , 4 , 5 , 6 ]

Initial
Profit Array =>	[ 0 , 0 , 0 , 0 , 0 , 0 , 0 ]

After 1st Pass => [ 78, 72, 72, 72, 72, 55, 0 ]

2nd Pass => 		[ 78, 100, 100, 100, 100, 100, 100 ]

*/

int calculateMax(const vector<int> &price) {
	int n = price.size();
	vector<int> profit(n,0); // This initializes vector of length n to 0
	int maxRight = price[n-1];
	for(int i=n-2;i>=0;i--) {
		if(maxRight < price[i])
			maxRight = price[i];
		profit[i] = max(profit[i+1],maxRight-price[i]);
	}
	int minLeft = price[0];
	for(int i=1;i<n;i++) {
		if(minLeft > price[i])
			minLeft = price[i];
		profit[i] = max(profit[i-1],profit[i] + price[i]-minLeft);
	}
	return profit[n-1];
}

int main() {
	vector<int> a = {2,30,15,10,8,25,80};
	cout << calculateMax(a) << "\n";
	return 0;
}
