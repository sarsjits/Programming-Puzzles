// Stock buy sell to maximize profit

#include <iostream>
#include <vector>

using namespace std;

struct stock {
	int buy;
	int sell;
};

vector<stock> stockProfit(const vector<int> &price) {
	vector<stock> stCount;
	int n = price.size();
	int i=0;
	while(i < n-1) {
		while(i < n-1 && price[i+1]<=price[i]) {
			i++;
		}
		if(i == n-1)
			break;
		stock temp;
		temp.buy = i++;
		
		while(i < n && price[i-1]<=price[i]) {
			i++;
		}
		temp.sell = i - 1;
		stCount.push_back(temp);
	}
	return stCount;
}

int main() {
	vector<int> a = {100,180,260,310,40,535,695};
	vector<stock> res = stockProfit(a);
	for(int i=0;i<res.size();i++) {
		cout << a[res[i].buy] << " " << a[res[i].sell] << "\n"; 
	}
	return 0;
}
