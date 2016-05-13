// Basics of dynamic programming
// Calculating fibonacci numbers using memoization (top-down) technique

#include <iostream>
#include <vector>

#define MAX 100
#define NIL -1

using namespace std;

vector<int> lookup(MAX,NIL);

int fib(int n) {
	if(lookup[n] == NIL) {
		if(n <= 1)
			lookup[n] = n;
		else {
			lookup[n] = fib(n-1) + fib(n-2);
		}
	}
	return lookup[n];
}

int main() {
	int n = 40;
	cout << fib(40) << "\n";
	return 0;
}
