// Longest Common Subsequence problem
// Using recursion as well as dynamic programming

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// Tabulation method
int lcsTabulated(string a,string b) {
	int n = a.size();
	int m = b.size();
	
	// L is the table we generate for calculating lcs
	// Dynamically creating the 2D array
	int **L = new int *[n+1];
	for(int i=0;i<n+1;i++) {
		L[i] = new int[m+1];
	}
	
	// Filling the table
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=m;j++) {
			if( i == 0 || j == 0 )
				L[i][j] = 0;
			else if(a[i-1] == b[j-1])
				L[i][j] = 1 + L[i-1][j-1];
			else
				L[i][j] = max(L[i][j-1],L[i-1][j]);
		}
	}
	
	int ans = L[n][m];
	
	// deleting the dynamically created 2D array
	for(int i=0;i<n+1;i++)
		delete [] L[i];
	delete [] L;
	
	return ans;
}

// Recursive method with O(2^n) complexity
int lcsRecursive(const char *a,const char *b,int n,int m) {
	// Base condition
	if(m == 0 || n == 0)
		return 0;
	if(a[n-1] == b[m-1])
		return 1 + lcsRecursive(a,b,n-1,m-1);
	else
		return max(lcsRecursive(a,b,n,m-1),lcsRecursive(a,b,n-1,m));
}

int main() {
	string a = "AGGTAB";
	string b = "GXTXAYB";
	const char *x = a.c_str(); // c_str will return const char *
	const char *y = b.c_str();
	cout << lcsRecursive(x,y,a.size(),b.size()) << "\n";
	cout << lcsTabulated(a,b) << "\n";
	return 0;
}
