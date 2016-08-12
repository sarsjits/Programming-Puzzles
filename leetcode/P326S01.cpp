class Solution {
public:
    static const int maxLog3 = log(numeric_limits<int>::max()) / log(3);
    static const int maxPower3 = pow(3,maxLog3);
    bool isPowerOfThree(int n) {
        // Interesting approaches at https://leetcode.com/articles/power-of-three/
        if(n>0 && maxPower3 % n == 0) return true;
        return false;
    }
};
