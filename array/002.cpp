// Find majority element using Moore's Voting algorithm

#include <iostream>
#include <vector>
using namespace std;

int findMajority(vector<int> &a);
bool isMajority(vector<int> &a,int maj);

int main() {
	vector<int> a = {1,2,2,2,2,3,4};
	int majElement = findMajority(a);
	if(isMajority(a,majElement)) {
		cout << "Majority element is: " << majElement << "\n";
	} else {
		cout << "No majority element.\n";
	}
	return 0;
}

int findMajority(vector<int> &a) {
	int majIdx = 0,count = 1;
	for(int i=0;i<a.size();i++) {
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
