// Check if array elements are consecutive

#include <iostream>
#include <map>
#include <vector>
#include <climits>

using namespace std;

bool isConsecutive(const vector<int> &a) {
	int max = -INT_MAX;
	int min = INT_MAX;
	map<int,bool> visited;
	for(int i=0;i<a.size();i++) {
		if(max < a[i])
			max = a[i];
		if(min > a[i])
			min = a[i];
		if(visited.find(a[i]) == visited.end()) {
			visited[a[i]] = true;
		} else {
			return false;
		}
	}
	if(max-min+1 == a.size())
		return true;
	return false;
}

int main() {
	vector<int> a = {4,3,2,1,4};
	if(isConsecutive(a) == true)
		cout << "Yes\n";
	else
		cout << "No\n";
}
