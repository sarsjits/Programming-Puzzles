// Sort element by frequency using sorting

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct element {
	int val;
	int idx;
	int cnt;
};

bool compVal(element a,element b) {
	return a.val < b.val;
}

bool comp(element a, element b) {
	if(a.cnt != b.cnt)
		return a.cnt < b.cnt;
	else
		return a.idx > b.idx;
}

void sortByFrequency(vector<int> &a) {
	element e[a.size()];
	for(int i=0;i<a.size();i++) {
		e[i].val = a[i];
		e[i].idx = i;
		e[i].cnt = 0;
	}
	stable_sort(e,e+a.size(),compVal);
	e[0].cnt = 1;
	for(int i=1;i<a.size();i++) {
		if(e[i].val == e[i-1].val) {
			e[i].cnt += e[i-1].cnt+1;
			e[i-1].cnt = -1;
			e[i].idx = e[i-1].idx;
		} else {
			e[i].cnt = 1;
		}
	}
	stable_sort(e,e+a.size(),comp);
	for(int i=a.size()-1,index=0;i>=0;i--) {
		if(e[i].cnt != -1) {
			for(int j=0;j<e[i].cnt;j++) {
				a[index++] = e[i].val;
			}
		}
	}
}

int main() {
	vector<int> a = {2,5,2,6,-1,999,5,8,8,8};
	sortByFrequency(a);
	for(int i=0;i<a.size();i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}
