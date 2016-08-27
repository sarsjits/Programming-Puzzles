class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> result;
        set<int> vec1;
        vector<int> ans;
        if(nums1.size() == 0 || nums2.size() == 0)
            return ans;
        for(auto val: nums1) {
            vec1.insert(val);
        }
        for(int i=0;i<nums2.size();++i) {
            if(vec1.find(nums2[i]) != vec1.end()) {
                result.insert(nums2[i]);
            }
        }
        for(auto it = result.begin(); it != result.end(); ++it) {
            ans.push_back(*it);
        }
        return ans;
    }
};
