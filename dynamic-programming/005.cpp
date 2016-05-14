// Minimum Cost Path
// One can traverse right, left and diagonally with equal weight

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <climits>

#define row 3
#define col 3

using namespace std;

// Using tabulated technique
int minCost(int **arr,int r, int c) {
	int **dp = new int*[r+1];
	for(int i=0;i<r+1;i++) {
		dp[i] = new int [c+1];
	}
	dp[0][0] = arr[0][0]; // Always
	for(int i=1;i<r+1;i++) {
		dp[i][0] = arr[i][0] + dp[i-1][0];
	}
	for(int j=1;j<c+1;j++) {
		dp[0][j] = arr[0][j] + dp[0][j-1];
	}
	
	for(int i=1;i<r+1;i++) {
		for(int j=1;j<c+1;j++) {
			dp[i][j] = arr[i][j] + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
		}
	}
	int ans = dp[r][c];
	for(int i=0;i<r+1;i++)
		delete [] dp[i];
	delete [] dp;
	return ans;
}

// Here parameter r & c represents the destination coordinater, where the start point (0,0)
int minCostRecur(int **arr,int r,int c) {
	if(r < 0 || c < 0)
		return INT_MAX;
	else if(r == 0 && c == 0) 
		return arr[r][c];
	else {
		return arr[r][c] + min( minCostRecur(arr,r-1,c-1), min ( minCostRecur(arr,r,c-1), minCostRecur(arr,r-1,c) ) );
	}
	return 0;
}

int main() {
	int **arr = new int *[row];
	for(int i=0;i<row;i++)
		arr[i] = new int [col];
	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;
	arr[1][0] = 4;
	arr[1][1] = 8;
	arr[1][2] = 2;
	arr[2][0] = 1;
	arr[2][1] = 5;
	arr[2][2] = 3;
	cout << minCostRecur(arr,row - 1,col - 1) << "\n";
	cout << minCost(arr,row - 1,col - 1) << "\n";
	return 0;
}
