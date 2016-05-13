// Pattern matching using Rabin-Karp Algorithm

#include <iostream>
#include <vector>
#include <string>

int d = 256; // Number of unique characters possible

using namespace std;

void search(string text, string pattern, int q) {
	int n = text.size();
	int m = pattern.size();
	int h = 1;
	int p = 0; // hash for pattern
	int t = 0; // hash for text
	// calculating h, which is used for calculating hash in O(1)
	for(int i=0;i<m-1;i++) {
		h = (h*d)%q;
	}
	// calculating hash for pattern and
	// first group of text
	for(int i=0;i<m;i++) {
		p = (d*p + pattern[i]) % q;
		t = (d*t + text[i]) % q;
	}
	
	// Now check for pattern matching by comparing hash
	// if hash matches, then check for each alphabet
	// else, calculate hash for next group of text and continue
	for(int i=0;i<n-m+1;i++) {
		if(p == t) {
			int j;
			for(j=0;j<m;j++) {
				if(text[i+j] != pattern[j])
					break;
			}
			if(j==m) {
				cout << "Pattern found at " << i << "\n";
			}
		}
		if(i < n-m) {
			t = (d*(t-text[i]*h)+text[i+m])%q;
			if(t<0) {
				t += q;
			}
		}
	}
}

int main() {
	string text = "HELLO HOW ARE YOU";
	string pattern = "HOW";
	int prime = 101;
	search(text,pattern,prime);
	return 0;
}
