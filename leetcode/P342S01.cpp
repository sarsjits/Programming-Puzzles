class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num > 0 && (num & (num-1)) == 0 && (num & 0b01010101010101010101010101010101))
            return true;
        return false;
    }
};
