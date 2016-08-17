/*
	Given Sorted and Rotated array, find if there is a pair with a given sum
	URL: http://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/
	Tests:
	1) {11,15,6,8,9,10} , 16
	2) {11,15,26,38,9,10} , 35
	3) {11,15,26,38,9,10} , 45
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	Method 1: Using two pointer method but in rotation
	Time: O(n)
	Space: O(1)
*/
bool pairExist(vector<int> &a, int sum) {
	// Find pivot in O(n)
	// Can be improved using binary search
	int i;
	for(i=0;i<a.size()-1;i++) {
		if(a[i+1] < a[i])
			break;
	}
	
	int left = (i+1)%a.size();
	int right = i;
	
	while(left != right) {
		int lrSum = a[left] + a[right];
		if(lrSum == sum) return true;
		if(lrSum < sum) {
			left = (left + 1) % a.size();
		} else {
			// Be aware
			right = (a.size() + right - 1) % a.size();
		}
	}
	return false;
}

int main (int argc, char const* argv[])
{
	vector<int> a = {11,15,6,8,9,10};
	if(pairExist(a,16) == true) cout << "Exist.\n";
	else cout << "Does not exist.\n";
	return 0;
}
