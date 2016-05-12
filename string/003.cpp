// Z Algorithm for pattern matching
// Z[k] := Longest substring starting at k which is also a prefix of the string
// https://www.youtube.com/watch?v=CpZh4eF8QBw
// http://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/
// http://www.utdallas.edu/~besp/demo/John2010/z-algorithm.htm

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void calculateZ(string str,int *Z) {
	// Covers the Z box;
	int len = str.size();
	int left = 0;
	int right = 0;
	int i;
	int k;
	
	// Calculation starts here
	Z[0] = 0; // Always
	
	for(i=1;i<len;i++) {
		if(i > right) {
			left = right = i;
			while(right < len && str[right] == str[right-left])
				right++;
			Z[i] = right - left;
			right--;
		} else {
			k = i - left;
			if(Z[k] < right - i + 1) {
				Z[i] = Z[k];
			} else {
				left = i;
				while(right < len && str[right] == str[right-left])
					right++;
				Z[i] = right - left;
				right--;
			}
		}
	}
}

void search(string text, string pattern) {
	string newString = pattern + "$" + text;
	int len = newString.size();
	int Z[len];
	calculateZ(newString,Z);
	
	for(int i=0;i<len;i++) {
		if(Z[i] == pattern.size()) {
			cout << "Pattern found at " << i - pattern.size() - 1 << "\n";
		}
	}
}

int main() {
	string text = "HELLO HOW ARE YOU";
	string pattern = "HOW";
	search(text,pattern);
	return 0;
}
