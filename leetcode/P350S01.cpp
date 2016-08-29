class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> Map;
        vector<int> ans;
        for(auto val: nums1) {
            if(Map.find(val) == Map.end()) Map[val] = 1;
            else Map[val]++;
        }
        for(auto val: nums2) {
            if(Map[val] > 0) {
                ans.push_back(val);
                Map[val]--;
            }
        }
        return ans;
    }
};
