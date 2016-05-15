#include <climits>
class Solution {
public:
    int reverse(int x) {
        bool isNeg = false;
        if(x<0) {
            x *= -1;
            isNeg = true;
        }
        long num = 0;
        while(x>0) {
            int rem = x%10;
            num = num*10 + rem;
            x /= 10;
        }
        if(num > INT_MAX)
            return 0;
        else if(isNeg == true){
            num *= -1;
        }
        return num;
    }
};
