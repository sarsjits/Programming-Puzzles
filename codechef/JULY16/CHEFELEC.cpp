#include <iostream>
#include <vector>
#include <string>
 
#define pb push_back
#define ll long long
 
using namespace std;
 
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string pattern;
		cin >> pattern;
		ll coord[n];
		vector<int> start,end;
		for(int i=0;i<n;i++) {
			cin >> coord[i];
		}
		int S,E;
		for(int i=0;i<n;i++) {
			if(pattern[i] == '1') {
				S = i;
				E = i;
				while(pattern[i] == '1') {
					i++;
					E++;
				}
				i--;
				E--;
				start.pb(S);
				end.pb(E);
			}
		}
		/*for(int i=0;i<start.size();i++) {
			cout << start[i] << " " << end[i] << "\n";
		}*/
		ll ans = 0;
		if(start[0] > 0) {
			ans += coord[start[0]] - coord[0];
		}
		for(int i=0;i<start.size()-1;i++) {
			int j;
			ll min = coord[start[i+1]] - coord[end[i]+1];
			for(j=end[i]+1;j<start[i+1]-1;j++) {
				ll tmp =  coord[j] - coord[end[i]] + coord[start[i+1]] - coord[j+1];
				if(tmp < min)
					min = tmp;
			}
			ll tmp = coord[j] - coord[end[i]];
			if(tmp < min)
				min = tmp;
			ans += min;
		}
		if(end[start.size()-1] < n-1) {
			ans += coord[n-1] - coord[end[start.size()-1]];
		}
		cout << ans << "\n";
	}
	return 0;
} 
