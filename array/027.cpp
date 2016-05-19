// Function to check whether a pythagorean triplet exist or not

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ifPythagorean(vector<int>& a) {
	if(a.size() == 0)
		return false;
	// Step 1: We square each element of the array
	for(int i=0;i<a.size();i++) {
		a[i] = a[i] * a[i];
	}
	
	// Step 2: sort all the elements
	sort(a.begin(),a.end());
	
	// Step 3: Use meet in the middle sort of algorithm to check 
	// whether any element as a^2 = b^2 + c^2 exist?
	// Since it is already squared
	// I will have to find whether x = y + z exist or not
	
	int x,y,z;
	for(x=a.size()-1;x>=2;x--) {
		y=0;z=x-1;
		while(y<z) {
			if(a[y]+a[z] == a[x])
				return true;
			else if(a[y]+a[z] > a[x])
				z--;
			else
				y++;
		}
	}
	return false;
}

int main() {
	vector<int> a = {5,3,4,1,2};
	if(ifPythagorean(a) == true)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
