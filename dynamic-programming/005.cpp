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

// Here parameter r & c represents the destination coordinater, where the start point (0,0)
int minCostRecur(int **arr,int r,int c) {
	if(r < 0 || c < 0)
		return INT_MAX;
	else if(r == 0 && c == 0) 
		return arr[r][c];
	else {
		
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
	minCostRecur(arr,row - 1,col - 1);
	return 0;
}
