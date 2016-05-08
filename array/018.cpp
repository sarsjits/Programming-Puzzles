// Sort 0,1 and 2 using Dutch National Flag Algorithm

#include <iostream>
#include <vector>

using namespace std;

void sort012(vector<int> &a) {
	int l = 0;
	int h = a.size()-1;
	int m = 0;
	while(m<=h) {
		switch(a[m]) {
			case 0:
				swap(a[l],a[m]);
				l++;
				m++;
				break;
			case 1:
				m++;
				break;
			case 2:
				swap(a[m],a[h]);
				h--;
				break;
		}
	}
}

int main() {
	vector<int> a = {0,1,0,2,1,1,1,2,2,2};
	sort012(a);
	for(int i=0;i<a.size();i++)
		cout << a[i] << " ";
	cout << "\n";
	return 0;
}
