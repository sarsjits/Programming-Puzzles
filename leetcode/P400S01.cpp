class Solution {
public:
    int findNthDigit(int n) {
        long long excluding [] = {9,90,900,9000,90000,900000,9000000,90000000,900000000,9000000000};
        int j = 1;
        int newNum = 0;
        int rem = 0;
        while(true) {
            if(n - j*excluding[j-1] > 0) {
                n -= j*excluding[j-1];
                newNum += excluding[j-1];
            } else {
                break;
            }
            ++j;
        }
        if(n % j == 0) {
            newNum += n/j;
            rem = j;
        } else {
            newNum = newNum + n/j + 1;
            rem = n % j;
        }
        
        string last = to_string(newNum);
        char ch = last[rem-1];
        
        return ch - '0';
    }
};
