// Find first non-repeating character from a string

#include <iostream>
#include <string>
#include <climits>

using namespace std;

struct countIdx {
	int count;
	int idx;
};

void getCharacterCount(string a,countIdx *c) {
	const char *str = a.c_str();
	int n = a.size();
	for(int i=0;i<n;i++) {
		c[str[i]].count++;
		if(c[str[i]].count == 1)
			c[str[i]].idx = i;
	}
}

int firstNonRepeating(string a) {
	countIdx count[256];
	for(int i=0;i<256;i++) {
		count[i].count = 0;
		count[i].idx = -1;
	}
	
	getCharacterCount(a,count);
	int minIdx = INT_MAX;
	for(int i=0;i<256;i++) {
		if(count[i].count == 1) {
			if(minIdx > count[i].idx)
				minIdx = count[i].idx;
		}
	}
	return minIdx;
}

int main() {
	string a = "JITENDRASARSWAT";
	int res = firstNonRepeating(a);
	if(res == INT_MAX)
		cout << "No non-repeating character or string is empty.\n";
	else
		cout << "First non-repeating character is: " << a[res] << "\n";
	return 0;
}
