// Coin changing: Minimum number of coins
// Time complexity: O(total*number of coins)
// Space complexity: O(total)
// https://www.youtube.com/watch?v=NJuKJ8sasGk&index=27&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr
// TODO: Find the coins which forms the result

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minNumCoins(const vector<int> &coins,int total) {
	int T[total+1];
	T[0] = 0;
	for(int i=1;i<=total;i++)
		T[i] = INT_MAX;
	for(int i=1;i<=total;i++) {
		for(int j=0;j<coins.size();j++) {
			if(i >= coins[j]) {
				int res = T[i-coins[j]];
				if(res != INT_MAX && res + 1 < T[i])
					T[i] = res + 1;
			}
		}
	}
	return T[total];
}

int main() {
	vector<int> coins = {8,2,6,3};
	int totalCountRequired = 12;
	int ans = minNumCoins(coins,totalCountRequired);
	if(ans != INT_MAX)
		cout << ans << "\n";
	else
		cout << "Not possible\n";
	return 0;
}
