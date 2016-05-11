// Naive pattern matching algorithm

#include <iostream>
#include <string>

using namespace std;

void patternSearch(string text,string pattern) {
	int n = text.size();
	int m = pattern.size();
	for(int i=0;i<=n-m;i++) {
		int j = 0;
		for(;j<m;j++) {
			if(text[i+j] != pattern[j])
				break;
		}
		if(j == m)
			cout << "Pattern found at index " << i << "\n"; 
	}
}

int main() {
	string text = "THIS IS ME";
	string pattern = "IS";
	patternSearch(text,pattern);
	return 0;
}
