// Rotating sorted array by reversing algorithm

#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int> &a,int s,int e) {
	while(s<e) {
		int temp = a[s];
		a[s] = a[e];
		a[e] = temp;
		s++;
		e--;
	}
}

void rotate(vector<int> &a,int d) {
	int n = a.size();
	reverse(a,0,d-1);
	reverse(a,d,n-1);
	reverse(a,0,n-1);
}

int main() {
	vector<int> a = {1,2,3,4,5};
	rotate(a,2);
	for(int i=0;i<a.size();i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}
