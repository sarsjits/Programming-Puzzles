/*
	Majority Element
	URL: http://bit.ly/1w25ZD8
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int findMajority(vector<int> &a);
bool isMajority(vector<int> &a,int maj);
int findMajorityMap(vector<int> &a);
int findMajorityUnMap(vector<int> &a);

int main() {
	vector<int> a = {1,2,2,2,2,3,4};
	int majElement = findMajorityUnMap(a);
	if(isMajority(a,majElement)) {
		cout << "Majority element is: " << majElement << "\n";
	} else {
		cout << "No majority element.\n";
	}
	return 0;
}

/*
	Method 1: Moore's Voting Algorithm
	Time Complexity: O(n)
	Space: O(1)
*/
int findMajority(vector<int> &a) {
	int majIdx = 0,count = 1;
	for(int i=1;i<a.size();i++) {
		if(a[majIdx] == a[i])
			count++;
		else
			count--;
		if(count == 0) {
			majIdx = i;
			count = 1;
		}
	}
	return a[majIdx];
}

bool isMajority(vector<int> &a,int maj) {
	int count = 0;
	for(int i=0;i<a.size();i++) {
		if(a[i] == maj)
			count++;
	}
	if(count > (a.size())/2)
		return true;
	return false;
}

/*
	Method 2: Using map
	Time Complexity: O(n*logn*logn) since map is implemented as Red Black Trees 
	Space Complexity: O(n)
*/

int findMajorityMap(vector<int> &a) {
	map<int, int> Map;
	for(int i=0;i<a.size(); i++) {
		if(Map.find(a[i]) == Map.end()) {
			Map[a[i]] = 1;
		} else {
			Map[a[i]]++;
		}
	}
	int maxOcur = 0;
	int max = 0;
	
	for(auto val : Map) {
		if(maxOcur < val.second) {
			maxOcur = val.second;
			max = val.first;
		}
	}
	
	if(maxOcur > 0) {
		return max;
	}
}

/*
	Method 3: Using un-ordered map
	Time complexity: O(n*1*1)
	Space: O(n)
*/

int findMajorityUnMap(vector<int> &a) {
	unordered_map<int, int> UnMap;
	for(int i=0;i<a.size(); i++) {
		if(UnMap.find(a[i]) == UnMap.end()) {
			UnMap[a[i]] = 1;
		} else {
			UnMap[a[i]]++;
		}
	}
	int maxOcur = 0;
	int max = 0;
	
	for(auto val : UnMap) {
		if(maxOcur < val.second) {
			maxOcur = val.second;
			max = val.first;
		}
	}
	
	if(maxOcur > 0) {
		return max;
	}
}
