// Longest pallindromic sequence
// https://www.youtube.com/watch?v=_nCsPn7_OgI&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=9

#include <iostream>
#include <string>

using namespace std;

// Using tabulated technique
int lps(string s) {
	int n = s.size();
	int dp[n][n];
	for(int i=0;i<n;i++)
		dp[i][i] = 1;
	// k here is the length of substring we are currently examining
	// starts with all substring of length of 2, then 3 and so on 
	// till it is equal to the length of original string
	for(int k=2;k<=n;k++) {
		// Ending condition of i is starting index where the last substring
		// under exmination is there, e.g. for k = 2 and n = 5
		// i must go till idx 4 so that the last substring of this length will be covered
		for(int i=0;i<n-k+1;i++) {
			// End idx of each substring under examination 
			int j = i+k-1;
			if(s[i] == s[j]) {
				if(k==2)
					dp[i][j] = 2;
				else
					dp[i][j] = 2 + dp[i+1][j-1];
			} else {
				dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
			}
		}
	}
	return dp[0][n-1];
}

int lpsRecur(string s,int i,int j) {
	if(i == j)
		return 1;
	if(s[i] == s[j]) {
		if(i+1 == j) {
			return 2;
		} else {
			return 2 + lpsRecur(s,i+1,j-1);
		}
	} else {
		return max(lpsRecur(s,i+1,j),lpsRecur(s,i,j-1));
	}
}

int main() {
	string str = "agbdba";
	cout << lpsRecur(str,0,str.size()-1) << "\n";
	cout << lps(str) << "\n";
	return 0;
}
