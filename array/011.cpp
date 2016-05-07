// Maximum sum such that no two elements are adjacent

#include <iostream>
#include <vector>

using namespace std;

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

int main() {
	vector<int> a = {5,5,10,40,50,35};
	cout << maxSum(a) << "\n";
	return 0;
}
