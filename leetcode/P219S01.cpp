class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;
        for(int i=0;i<nums.size();++i) {
            if(s.find(nums[i]) != s.end())
                return true;
            s.insert(nums[i]);
            if(i-k>=0)
                s.erase(nums[i-k]);
        }
        return false;
    }
};
