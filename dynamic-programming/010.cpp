// Longest Pallindromic Substring
// https://www.youtube.com/watch?annotation_id=annotation_1075415315&feature=iv&src_vid=U4yPae3GEO0&v=obBdxeCx_Qs

#include <iostream>
#include <string>

using namespace std;
struct res {
	int maxLen;
	int idx;
	string substring;
};

res lps(string s) {
	res result;
	// This result is always expected 
	result.maxLen = 1;
	result.idx = 0;
	result.substring = s[0];
	int n = s.size();
	bool dp[n][n];
	// It may be hard to debug but initially all the array values are not set to false
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(i == j)
				dp[i][j] = true;
			else
				dp[i][j] = false;
		}
	}
	//Current length
	for(int cl = 2;cl<=n;cl++) {
		for(int i =0;i<n-cl+1;i++) {
			int j = i+cl-1;
			if(s[i] == s[j]) {
				if(cl == 2) {
					dp[i][j] = true;
					result.maxLen = cl;
					result.idx = i;
				}
				else if(dp[i+1][j-1] == true) {
					dp[i][j] = true;
					result.maxLen = cl;
					result.idx = i;
				}
			}
		}
	}
	result.substring = s.substr(result.idx,result.maxLen);
	return result;
}

int main() {
	string str = "agbdba";
	res result = lps(str);
	cout << result.maxLen << ": " << result.substring << "\n";
	return 0;
}
