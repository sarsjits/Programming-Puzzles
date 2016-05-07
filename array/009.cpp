// Rotate the sorted array using juggling algorithm

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

// d is the length by which the array is to be rotated
void rotate(vector<int> &a,int d) {
	int n = a.size();
	int gcdDN = gcd(d,n);
	for(int i=0;i<gcdDN;i++) {
		int j = i;
		int temp = a[j];
		while(true) {
		//Number of iterations are equal to n/gcd(d,n)
			int k = j + d;
			if(k >= n)
				k -= n;
			if(k == i)
				break;
			a[j] = a[k];
			j = k;
		}
		a[j] = temp;
	}
}

int main() {
	vector<int> a = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	rotate(a,12);
	for(int i=0;i<a.size();i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}
