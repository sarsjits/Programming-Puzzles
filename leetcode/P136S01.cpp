class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for(auto val: nums)
            sum ^= val;
        return sum;
    }
};
