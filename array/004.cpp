// Find the number occurring one time and all other occurrs twice, in sorted order.

#include <iostream>
#include <vector>
using namespace std;

int findTheODD(vector<int> &a) {
	int l = 0;
	int r = a.size() - 1;
	while(l<=r) {
		int m = l + (r-l)/2;
		if(m+1 < a.size() && a[m] == a[m+1]) {
			if((m&1)==0)
				l = m+1;
			else
				r = m-1;
		} else if(m-1>=0 && a[m] == a[m-1]) {
			if((m&1)==0)
				r = m-1;
			else
				l = m+1;
		} else {
			return a[m];
		}
	}
}

int main() {
	vector<int> a = {101,101,201,201,401,401,501};
	cout << findTheODD(a) << "\n";
	return 0;
}
