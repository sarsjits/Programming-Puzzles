class Solution {
public:
    int countPrimes(int n) {
        bool arr[n+1];
        arr[0] = false;
        arr[1] = false;
        for(int i=2;i<=n;i++) arr[i] = true;
        for(int i=2;i<=sqrt(n);i++) {
            if(arr[i] == true) {
                for(int j=2*i;j<=n;j+=i) {
                    arr[j] = false;
                }
            }
        }
        int count = 0;
        for(int i=2;i<n;i++) {
            if(arr[i] == true) count++;
        }
        return count;
    }
};
