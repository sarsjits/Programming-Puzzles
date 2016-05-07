// Segregate 0s and 1s efficiently

#include <iostream>
#include <vector>

using namespace std;

// Assuming 0s to the left and 1s to the right
void filter(vector<int> &a) {
	int start = 0;
	int end = a.size()-1;
	while(start < end) {
		while(a[start] == 0) start++;
		while(a[end] == 1) end--;
		int tmp = a[start];
		a[start] = a[end];
		a[end] = tmp;
		start++;
		end--;
	}
}

int main() {
	vector<int> a = {1,1,0,1};
	filter(a);
	for(int i=0;i<a.size();i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}
