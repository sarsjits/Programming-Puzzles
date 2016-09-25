class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        long long powerFive = 5;
        while(n/powerFive > 0) {
            count += n/powerFive;
            powerFive *= 5;
        }
        return count;
    }
};
