class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0)
            return res;
        if(nums.size() == 1) {
            res.push_back(to_string(nums[0]));
            return res;
        }
        string arrow = "->";
        for(int i=0;i<nums.size()-1;i++) {
            int count = 1,j;
            string now = to_string(nums[i]);
            for(j = i;j<nums.size()-1;j++) {
                if(nums[j+1] - nums[j] == 1) {
                    count++;
                } else {
                    break;
                }
            }
            i = j;
            if(count > 1 && j != nums.size()-1) {
                now += arrow;
                now += to_string(nums[j]);
            } else if(count > 1 && j == nums.size()-1) {
                now += arrow;
                now += to_string(nums[j]);
            }
            res.push_back(now);
        }
        if(nums[nums.size()-1] - nums[nums.size()-2] != 1 ) {
            res.push_back(to_string(nums[nums.size()-1]));
        }
        return res;
    }
};
