class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int i=0,j=0;
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i] == nums[i+1])
                continue;
            else
                nums[++j] = nums[i+1];
        }
        return j+1;
    }
};
