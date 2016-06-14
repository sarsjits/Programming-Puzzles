class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t newNum = 0, i, isSet;
        for(i=0;i<32;i++) {
            isSet = (n & (1<<i));
            if(isSet) {
              newNum |= (1 << (32-1)-i);  
            }
        }
        return newNum;
    }
};
