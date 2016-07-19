class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        if(digits.size() == 0) {
            res.push_back(1);
            return res;
        }
        
        int curSum = 0, carry = 0, i = digits.size() - 1;
        if(digits[i] + 1 == 10) {
            carry = 1;
            while(carry != 0) {
                curSum = digits[i] + carry;
                if(curSum == 10) {
                    curSum = 0;
                    carry = 1;
                } else {
                    carry = 0;
                }
                res.push_back(curSum);
                i--;
            }
        } else {
            res.push_back(digits[i]+1);
            i--;
            carry = 0;
        }
        for(;i>=0;i--) {
            res.push_back(digits[i]);
        }
        if(carry == 1) {
            res.push_back(carry);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
