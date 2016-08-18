/* 
	Maximum sum such that no two elements are adjacent
	URL: http://bit.ly/2bAurt3
*/

#include <iostream>
#include <vector>

using namespace std;

/*
	Method 1: Does not work for the negative numbers
	Time: O(n)
	Space: O(1)
*/
int maxSum(vector<int> &a) {
	int incl = a[0]; // Maximum sum including prev element for idx 1
	int excl = 0; // MAximum sum excluding prev element for idx 1
	// sum including current element = excl + cur
	// sum excluding current element = max(incl,excl)
	
	for(int i=1;i<a.size();i++) {
		int excl_new = max(incl,excl);
		incl = excl + a[i];
		excl = excl_new;
	}
	return max(incl,excl);
}

/*
	Method 2: Using Dynamic Programming
	Simple yet useful explanation at URL: http://bit.ly/2b3R2yr
	Read answer by codaddict
	Time: O(n)
	Space: O(n)
*/

int maxSumDP(vector<int> &a) {
	int sum[a.size()];
	for(int i=0;i<a.size();++i) {
		if(i == 0)
			sum[0] = a[0];
		else if(i == 1)
			sum[1] = max(a[1],sum[0]);
		else
			sum[i] = max(sum[i-2]+a[i],sum[i-1]);
	}
	return sum[a.size()-1];
}

int main() {
	vector<int> a = {5,5,10,40,50,35};
	cout << maxSumDP(a) << "\n";
	return 0;
}
