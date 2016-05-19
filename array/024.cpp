// Find smallest and second smallest element in the array
// One pass

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void firstSecondSmallest(const vector<int> &a) {
	int n = a.size();
	int first = INT_MAX;
	int second = INT_MAX;
	for(int i=0;i<n;i++) {
		if(first > a[i]) {
			second = first;
			first = a[i];
		} else if(second > a[i] && a[i] != first) {
			second = a[i];
		}
	}
	if(second == INT_MAX)
		cout << "No second smallest element\n";
	else
		cout << "First smallest: " << first << " and second smallest: " << second << "\n";
}

int main() {
	vector<int> a = {1,5,3,2,6,9};
	firstSecondSmallest(a);
	return 0;
}
