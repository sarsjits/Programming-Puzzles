#include <iostream>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int sum = 0;
        int x;
        bool ans = true;
        bool isFive = false;
        for(int i=0;i<n;i++) {
            cin >> x;
            if(x <= 2)
                ans = false;
            if(x == 5)
                isFive = true;
            sum += x;
        }
        float avg = ( (float)sum/n );
        if(avg < 4)
            ans = false;
        if(ans == true && isFive == true)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
	return 0;
}
