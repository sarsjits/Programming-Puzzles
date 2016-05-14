// Minimum Edit Distance to convert one string to another
// Allowed operations are:
// Insert, Delete, Replace (Assume all operations are of same cost)

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
// Calculating edit distance using tabulated technique
int editDistance(string a, string b) {
	int n = a.size();
	int m = b.size();
	
	// Creating the 2D array dynamically
	int **dp = new int *[n+1];
	for(int i=0;i<n+1;i++) {
		dp[i] = new int[m+1];
	}
	
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=m;j++) {
			if(i == 0)
				dp[i][j] = j;
			else if(j == 0)
				dp[i][j] = i;
			else if(a[i-1] == b[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
		}
	}
	
	int ans = dp[n][m];
	
	for(int i=0;i<n+1;i++)
		delete [] dp[i];
	delete [] dp;
	
	return ans;
}

int editDistanceRecur(const char *a,const char *b,int n,int m) {
	if(m == 0) return n;
	if(n == 0) return m;
	if(a[n-1] == b[m-1])
		return editDistanceRecur(a,b,n-1,m-1);
	else {
		return 1 + min(
							editDistanceRecur(a,b,n-1,m-1), //Replace
							min ( editDistanceRecur(a,b,n,m-1), // Insert
							editDistanceRecur(a,b,n-1,m) )  );// delete
	}
}

int main() {
	string a = "sunday";
	string b = "saturday";
	const char *x = a.c_str();
	const char *y = b.c_str();
	cout << editDistanceRecur(x,y,a.size(),b.size()) << "\n";
	cout << editDistance(a,b) << "\n";
	return 0;
}
