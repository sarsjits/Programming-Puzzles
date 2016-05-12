// KMP String matching algorithm

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// LPS: Longest Common Prefix which is also Suffix
void computeLPS(string pattern, int *lps) {
	int len = 0;
	lps[len] = 0; // lps[0] is always 0
	int m = pattern.size();
	int i = 1;
	while(i<m) {
		if(pattern[len] == pattern[i]) {
			len++;
			lps[i] = len;
			i++;
		} else {
			if(len != 0) {
				len = lps[len-1];
			} else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMP(string text,string pattern) {
	int n = text.size();
	int m = pattern.size();
	int LPS[m];
	computeLPS(pattern,LPS);
	int i = 0;
	int j = 0;
	while(i<n) {
		if(text[i] == pattern[j]) {
			i++;
			j++;
		}
		if(j == m) {
			cout << "Pattern found at " << i-j << "\n";
		} else if(i<n && text[i] != pattern[j]){
			if(j != 0)
				j = LPS[j-1];
			else
				i++;
		}
	}
}

int main() {
	string text = "ABABDABACDABABCABAB";
	string pattern = "ABABCABAB";
	KMP(text,pattern);
	return 0;
}
