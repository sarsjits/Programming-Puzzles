class Solution {
public:
    bool isHappy(int n) {
        // Not considering 0, since the problem mentions positive numbers
        set<int> s;
        while(n != 1 && s.find(n) == s.end()) {
            s.insert(n);
            n = modifiedN(n);
        }
        if(n == 1) return true;
        else return false;
    }
    int modifiedN(int n) {
        int sum = 0;
        while(n > 0) {
            sum = sum + ((n % 10)*(n % 10));
            n /= 10;
        }
        return sum;
    }
};
