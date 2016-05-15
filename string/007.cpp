/*
	Zigzag string coversion
	Suppose string is JITENDRASARSWAT and rows = 3
	then zigzag string would look like
	Input:
	
	J   N   S   W    
	 I E D A A S A      
	  T   R   R   T
	  
	So the final output should be to print the string row wise
	Output:
	
	JNSWIEDAASATRRT
	
	http://www.geeksforgeeks.org/print-concatenation-of-zig-zag-string-form-in-n-rows/
*/

#include <iostream>
#include <string>

using namespace std;

void zigzag(const string s, int rows) {
	int n = s.size();
	bool down = true;
	int row = 0;
	string arr[rows];
	for(int i=0;i<n;i++) {
		arr[row].push_back(s[i]);
		if(row == rows-1)
			down = false;
		if(row == 0)
			down = true;
		if(down == true)
			row++;
		else
			row--;
	}
	for(int i=0;i<rows;i++)
		cout << arr[i];
	cout << "\n";
}

int main() {
	string str = "JITENDRASARSWAT";
	int rows = 3;
	zigzag(str,rows);
	return 0;
}
