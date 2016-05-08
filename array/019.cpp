// Find equilibrium index in the array

#include <iostream>
#include <vector>

using namespace std;

int equi(const vector<int> &a){
	int sum = 0;
	for(int i=0;i<a.size();i++) {
		sum += a[i];
	}
	int leftSum = 0;
	for(int i=0;i<a.size();i++) {
		sum -= a[i];
		if(leftSum == sum)
			return i;
		leftSum += a[i];
	}
	return -1;
}

int main() {
	vector<int> a = {1,2,3,4,5,6,5,4,3,2,1};
	int ans = equi(a);
	if(ans == -1)
		cout << "No equilibrium index found.\n";
	else
		cout << "Equilibrium index: " << ans << "\n";
	return 0;
}
