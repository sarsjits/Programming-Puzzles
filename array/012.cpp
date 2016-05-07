// Leaders in the array: If the element is greater all the elements in the right
// first thought

#include <iostream>
#include <vector>

using namespace std;

vector<int> findLeader(vector<int> &a) {
	vector<int> res;
	res.push_back(a[a.size()-1]);
	int maxSoFar = a[a.size()-1];
	for(int i = a.size()-2; i>=0 ; i--) { 
		if(a[i] > maxSoFar) {
			maxSoFar = a[i];
			res.push_back(a[i]);
		}
	}
	return res;
}

int main() {
	vector<int> a = {16,17,4,3,5,2};
	vector<int> res = findLeader(a);
	for(int i=0;i<res.size();i++) {
		cout << res[i] << " ";
	}
	cout << "\n";
	return 0;
}
