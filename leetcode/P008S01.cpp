#include <climits>

class Solution {
public:
    int myAtoi(string str) {
        int n = str.length();
        const char *s = str.c_str();
        int i=0;
        long long num=0;
        bool isNeg = false;
        while(s[i] == ' ') i++;
        if(i == n)
            return 0;
        if(s[i] == '-') {
            isNeg = true;
            i++;
        } else if(s[i] == '+'){
            i++;
        } else if(s[i]<48 || s[i]>57) {
            return 0;
        }
        
        for(;i<n;i++) {
            if(s[i]>=48 && s[i]<=57) {
                num = num*10 + (s[i]-'0');
                if(isNeg == true)
                    num *= -1;
                if(num > INT_MAX)
                    return INT_MAX;
                else if(num < INT_MIN)
                    return INT_MIN;
                if(isNeg == true)
                    num *= -1;
            } else {
                break;
            }
        }
        if(isNeg == true)
            num *= -1;
        
        return num;
    }
};
