// Maximize number of A's using only 4 keys
// 'A',Ctrl+A,Ctrl+V,Ctrl+C
// http://zillionthoughts.com/find-maximum-number-using-keys-ctrla-ctrlc-ctrlv/
// http://edusagar.com/questions/dynamic-programming/maximum-number-of-a-using-ctrl-a-ctrl-c-ctrl-v-keys-google-interview-question
// http://articles.leetcode.com/ctrla-ctrlc-ctrlv/

// This solution assumes that We need not paste twice to double the number of A's which is assumed in Leetcode question

#include <iostream>
#include <vector>

using namespace std;

// Using tabulated technique
int maxAs(int n) {
	if(n <= 6)
		return n;
	int screen[n+1];
	screen[0] = 0;
	for(int i=1;i<=6;i++)
		screen[i] = i;
	for(int i=7;i<=n;i++) {
		screen[i] = 0;
		for(int b=n-3;b>=1;b--) {
			int cur = (i-b-1) * screen[b];
			if(screen[i] < cur)
				screen[i] = cur;
		}
	}
	return screen[n];
}

int maxAsRecur(int n) {
	if(n<=6)
		return n;
	int max = 0;
	int b;
	for(b=n-3;b>=1;b--) {
		int cur = (n-b-1)*maxAsRecur(b);
		if(cur>max)
			max = cur;
	}
	return max;
}

int main() {
	for(int i=1;i<=20;i++)
		cout << "Number of As for i = " << i << ": " << maxAs(i) << "\n";
	return 0;
}
