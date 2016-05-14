// Find if first string is a subsequence of second string

#include <iostream>
#include <string>

using namespace std;

bool isSubstring(const char *a,const char *b,int n, int m) {
	// Base cases
	if(n == 0) return false;
	if(m == 0) return true;
	
	if(a[n-1] == b[m-1]) return isSubstring(a,b,n-1,m-1);
	else return isSubstring(a,b,n-1,m);
} 

int main() {
	string a = "HELLO HOW ARE YOU";
	string b = "WOG";
	const char *x = a.c_str();
	const char *y = b.c_str();
	if(isSubstring(x,y,a.size(),b.size()) == true)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
